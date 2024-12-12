import random
import matplotlib.pyplot as plt
import matplotlib.patches as patches
from matplotlib.animation import FuncAnimation

grid_size = 20

num_squares = 20
squares = set()
while len(squares) < num_squares:
    x = random.randint(0, grid_size - 1)
    y = random.randint(0, grid_size - 1)
    squares.add((x, y))

snake_length = 3
snake = [(random.randint(0, grid_size - 1), random.randint(0, grid_size - 1))]
snake_patches = []
directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

def move_snake():
    global snake
    head_x, head_y = snake[-1]

    while True:
        direction = random.choice(directions)
        new_head = (head_x + direction[0], head_y + direction[1])
        
        if len(snake) > 1 and new_head == snake[-2]:
            continue
        if 0 <= new_head[0] < grid_size and 0 <= new_head[1] < grid_size:
            break

    if new_head in squares or new_head in snake:
        return False

    snake.append(new_head)
    if len(snake) > snake_length:
        snake.pop(0)

    return True

def update(frame):
    global snake, snake_patches

    if not move_snake():
        animation.event_source.stop()
        print("Koniec gry!")
        return 

    for patch in snake_patches:
        patch.remove()
    snake_patches.clear()

    for segment in snake:
        square = patches.Rectangle(segment, 1, 1, edgecolor='green', facecolor='green')
        ax.add_patch(square)
        snake_patches.append(square)

fig, ax = plt.subplots(figsize=(10, 10))
ax.set_xlim(0, grid_size)
ax.set_ylim(0, grid_size)
ax.set_xticks(range(0, grid_size + 1, 1))
ax.set_yticks(range(0, grid_size + 1, 1))
ax.set_aspect('equal')
ax.grid()

for square in squares:
    sq = patches.Rectangle(square, 1, 1, edgecolor='red', facecolor='red')
    ax.add_patch(sq)

animation = FuncAnimation(fig, update, frames=200, interval=200, repeat=False)
plt.show()

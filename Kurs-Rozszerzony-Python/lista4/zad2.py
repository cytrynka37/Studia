#Kaja Matuszewska 345951 lista 4 zadanie 2
import itertools

class FormulaTypeError(TypeError):
    """Raised when wrong type to a Formula subclass is provided."""
    pass

class NotAssignedVariableError(TypeError):
    """Raised when a variable doesn't have assigned value during evaluation."""
    pass

class Formula:
    def eval(self, variables):
        pass

    def __str__(self):
        pass
    
    def eval(self):
        pass
    
    def __add__(self, other):
        if not isinstance(other, Formula):
            raise FormulaTypeError("Right operand must be a Formula.")
        return Or(self, other)

    def __mul__(self, other):
        if not isinstance(other, Formula):
            raise FormulaTypeError("Right operand must be a Formula.")
        return And(self, other)

    def get_variables(self):
        return set()

    def is_tautology(self):
        variables = {v for v in self.get_variables()}
        for values in itertools.product([True, False], repeat=len(variables)):
            vars = dict(zip(variables, values))
            if not self.eval(vars):
                return False
        return True

    def simplify(self):
        return self


class Constant(Formula):
    def __init__(self, value):
        if not isinstance(value, bool):
            raise FormulaTypeError("Constant value must be a boolean.")
        self.value = value

    def __str__(self):
        return str(self.value)
    
    def eval(self, variables):
        return self.value
    

class Variable(Formula):
    def __init__(self, name):
        if not isinstance(name, str):
            raise FormulaTypeError("Variable name must be a string.")
        self.name = name

    def __str__(self):
        return self.name
    
    def eval(self, variables):
        if self.name not in variables:
            raise NotAssignedVariableError(self.name)
        return variables.get(self.name, False)

    def get_variables(self):
        return {self.name}
    

class Not(Formula):
    def __init__(self, formula):
        if not isinstance(formula, Formula):
            raise FormulaTypeError("Not operand must be a Formula.")
        self.formula = formula

    def __str__(self):
        return f"¬{self.formula}"
    
    def eval(self, variables):
        return not self.formula.eval(variables)

    def get_variables(self):
        return self.formula.get_variables()
    
    def simplify(self):
        if isinstance(self.formula, Constant):
            return Constant(not self.formula.value)
        return self
    

class And(Formula):
    def __init__(self, left, right):
        if not isinstance(left, Formula) or not isinstance(right, Formula):
            raise FormulaTypeError("Both operands of And must be Formula instances.")
        self.left = left
        self.right = right

    def __str__(self):
        return f"({self.left} ∧ {self.right})"
    
    def eval(self, variables):
        return self.left.eval(variables) and self.right.eval(variables)
    
    def get_variables(self):
        return self.left.get_variables().union(self.right.get_variables())
    
    def simplify(self):
        left_simplified = self.left.simplify()
        right_simplified = self.right.simplify()

        if isinstance(left_simplified, Constant):
            if left_simplified.value == True:
                return right_simplified
            else:
                return Constant(False)
        if isinstance(right_simplified, Constant):
            if right_simplified.value == True:
                return left_simplified
            else:
                return Constant(False)
        
        return And(left_simplified, right_simplified)


class Or(Formula):
    def __init__(self, left, right):
        if not isinstance(left, Formula) or not isinstance(right, Formula):
            raise FormulaTypeError("Both operands of Or must be Formula instances.")
        self.left = left
        self.right = right

    def __str__(self):
        return f"({self.left} ∨ {self.right})"
    
    def eval(self, variables):
        return self.left.eval(variables) or self.right.eval(variables)

    def get_variables(self):
        return self.left.get_variables().union(self.right.get_variables())
    
    def simplify(self):
        left_simplified = self.left.simplify()
        right_simplified = self.right.simplify()

        if isinstance(left_simplified, Constant):
            if left_simplified.value == True:
                return Constant(True)
            else:
                return right_simplified
        if isinstance(right_simplified, Constant):
            if right_simplified.value == True:
                return Constant(True)
            else:
                return right_simplified
        
        return Or(left_simplified, right_simplified)


f1 = Or(Variable("p"), Not(Variable("p")))
f2 = And(Variable("r"), Constant(True)) * f1
f3 = Or(Constant(True), Variable("r"))

print(f"is {f1} tautology? {f1.is_tautology()}")
print(f"{f2} simplified: {f2.simplify()}")
print(f"{f3} simplified: {f3.simplify()}")
print(f"is {f3} tautology? {f3.is_tautology()}")

try:
    print(Variable(123))
except FormulaTypeError as e:
     print(f"Error: {e}")
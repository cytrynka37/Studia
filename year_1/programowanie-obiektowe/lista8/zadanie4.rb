#Kaja Matuszewska lista 8 zadanie 4
class Explicit
    def initialize(text)
        @text = text
    end

    def encrypt(key)
        encrypted_text = ""
        @text.each_char do |char|
            encrypted_text += key[char] || char
        end
        Implicit.new(encrypted_text)
    end

    def to_s
        @text
    end
end

class Implicit
    def initialize(text)
        @text = text
    end

    def decrypt(key)
        decrypted_text = ""
        @text.each_char do |char|
            decrypted_text += key.key(char) || char
        end
        Explicit.new(decrypted_text)
    end

    def to_s
        @text
    end
end

key = {
  'a' => 'b',
  'b' => 'r',
  'r' => 'y',
  'y' => 'u',
  'u' => 'a',
  '1' => '2',
  '!' => '?'
}

text = Explicit.new("ruby!1")
encrypted_text = text.encrypt(key)
puts "Tekst: #{text}"
puts "Zaszyfrowany: #{encrypted_text}"

decrypted_text = encrypted_text.decrypt(key)
puts "Odszyfrowany: #{decrypted_text}"
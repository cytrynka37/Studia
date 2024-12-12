#Kaja Matuszewska lista 8 zadanie 3
class ONP
    def initialize(expr)
      @expression = expr
    end
  
    def calc(variables)
      stack = []
  
      @expression.each do |element|
        if element.is_a?(Integer)
          stack.push(element)
        elsif variables.key?(element)
          stack.push(variables[element])
        elsif element =~ /[+\-\*\/]/
          e1 = stack.pop
          e2 = stack.pop
          if e1.nil? || e2.nil?
            raise "Niepoprawne wyyrażenie: operator #{element} wymaga dwoch argumentów!"
          end
          stack.push(eval(element, e2, e1))
        else raise "Niepoprawne wyyrażenie"
        end
        puts "Stack: #{stack}"
      end
      result = stack.pop
      if !stack.empty?
        raise "Niepoprawne wyyrażenie"
      end
  
      result
    end
  
    private
    def eval(operator, e1, e2)
      case operator
      when '+'
        e1 + e2
      when '-'
        e1 - e2
      when '*'
        e1 * e2
      when '/'
        e1 / e2
      end
    end
  end

  variables = {'x' => 10, 'y' => 20}
  expression = ["x", "y", '+', 4, 2, '-', 5, '*', '/']
  onp_expression = ONP.new(expression)
  result = onp_expression.calc(variables)
  puts "Wynik: #{result}"
  
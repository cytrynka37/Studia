{
open Parser
}

let white = [' ' '\t']+
let digit = ['0'-'9']
let number = '-'? digit+

rule read =
  parse
  | white { read lexbuf }  
  | "=" { EQ }
  | "<>" { NEQ }
  | "<=" { LEQ }  
  | "<" { LS }
  | ">=" { GEQ }
  | ">" { GR }
  | "&&" { AND }
  | "||" { OR }
  | "true" { TRUE }
  | "false" { FALSE }
  | "if" { IF }
  | "then" { THEN }
  | "else" { ELSE }
  | "*" { TIMES }
  | "+" { PLUS }
  | "-" { MINUS }
  | "/" { DIV }
  | "(" { LPAREN }
  | ")" { RPAREN }
  | number { INT (int_of_string (Lexing.lexeme lexbuf)) } 
  | eof { EOF }

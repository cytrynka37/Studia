import Data.Char

data StreamTrans i o a
    = Return a
    | ReadS (Maybe i -> StreamTrans i o a)
    | WriteS o (StreamTrans i o a)

toLowerS :: StreamTrans Char Char ()
toLowerS = ReadS f
  where
    f (Just i) = WriteS (toLower i) toLowerS
    f _ = Return ()

runIOStreamTrans :: StreamTrans Char Char a -> IO a
runIOStreamTrans (Return a) = return a
runIOStreamTrans (ReadS f) = do
    c <- getChar
    runIOStreamTrans $ f (Just c)
runIOStreamTrans (WriteS o c) = do
    putChar o
    runIOStreamTrans c

listTrans :: StreamTrans i o a -> [i] -> ([o], a)
listTrans (Return a) _ = ([], a)
listTrans (ReadS f) (l:ls) = listTrans (f (Just l)) ls
listTrans (ReadS f) [] = listTrans (f Nothing) []
listTrans (WriteS o c) ls =
    let (x, a) = listTrans c ls
    in (o:x, a)
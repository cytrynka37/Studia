module Main where

import Data.Char

echoLower :: IO ()
echoLower = do
    c <- getChar
    putChar $ toLower c
    echoLower

main :: IO ()
main = echoLower
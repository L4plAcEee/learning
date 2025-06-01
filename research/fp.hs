add :: Int -> Int -> Int
add a b = a + b

makeAdderWithOffset :: Int -> (Int -> Int -> Int)
makeAdderWithOffset offset = \a b -> a + b + offset

squared = map (\x -> x * x) [1,2,3,4,5]

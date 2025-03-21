def fact(x, acc = 1)
  if x < 2
    return acc
  end

  acc *= x
  fact(x - 1, acc)
end

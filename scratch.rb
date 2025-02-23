class Rat
  include Comparable

  attr_reader :numerator, :denominator

  def initialize(numerator, denominator)
    @numerator, @denominator = simplify(numerator, denominator)
  end

  def *(other)
    Rat.new(numerator * other.numerator, denominator * other.denominator)
  end

  def /(other)
    Rat.new(numerator * other.denominator, denominator * other.numerator)
  end

  def +(other)
    new_denominator = denominator * other.denominator
    left = numerator * other.denominator
    right = other.numerator * denominator
    Rat.new(left + right, new_denominator)
  end

  def -(other)
    new_denominator = denominator * other.denominator
    left = numerator * other.denominator
    right = other.numerator * denominator
    Rat.new(left - right, new_denominator)
  end

  def to_s
    "(#{numerator}/#{denominator})"
  end

  def <=>(other)
    left_numerator = numerator * other.denominator
    right_numerator = other.numerator * denominator
    left_numerator <=> right_numerator
  end

  private

  attr_writer :numerator, :denominator

  def gcd_euclid(larger, smaller)
    loop do
      return larger if smaller.zero?
      remainder = larger % smaller
      larger, smaller = smaller, remainder
    end
  end

  def simplify(numerator, denominator)
    larger = (numerator > denominator ? numerator : denominator)
    smaller = (numerator < denominator ? numerator : denominator)
    gcd = gcd_euclid(larger, smaller)
    new_numerator = numerator / gcd
    new_denominator = denominator / gcd
    if new_denominator.negative?
      new_numerator = -new_numerator
      new_denominator = -new_denominator
    end
    [new_numerator, new_denominator]
  end
end

a = Rat.new(1, 2)
b = Rat.new(1, 3)

puts a > b
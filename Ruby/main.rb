require_relative "prism"

puts "Введи высоту призмы:"
height = Prism.get_height
length_of_sides = Prism.get_length_of_sides
prism = Prism.new(height, length_of_sides)
prism.show_menu

# Class Prism
class Prism
	attr_accessor :height, :length_of_sides, :square_of_base, :value, :count_of_edges

	def initialize(height, length_of_sides)
		@height = height
		@length_of_sides = length_of_sides
		calculate_square_of_base
		calculate_value
		@count_of_edges = 5
	end

	def self.get_height
		bad_input = true
		height = 0
		while bad_input do
			height = gets.chomp.to_i
			if height > 0
				bad_input = false 
			else
				puts "Введи корректную высоту"
			end
		end 
		height
	end

	def self.get_length_of_sides
		bad_input = true
		length_of_sides = []
		while bad_input do
			0.upto(2) do |i|
				puts "Введи #{i + 1}-ую сторону:"
				length_of_sides[i] = gets.chomp.to_i
			end
			a, b, c = length_of_sides
			if((a > 0) && (b > 0) && (c > 0) && (a + b > c) && (b + c > a) && (c + a > b))
				bad_input = false
			else
				puts "Треугольник с указанными сторонами не существует"
			end
		end 
		length_of_sides
	end

	def calculate_square_of_base
		a, b, c = @length_of_sides
		half_perimeter = (a + b + c) / 2.0
		@square_of_base = Math.sqrt(half_perimeter * (half_perimeter - a) * (half_perimeter - b) * (half_perimeter - c))
	end

	def calculate_value
		@value = square_of_base * height
	end
	
	def get_info
		puts "--------------------------------"
		puts "Объём -- " + @value.to_s
		puts "Площадь основания -- " + @square_of_base.to_s
        puts "Высота -- " + @height.to_s
        puts "Количество граней -- " + @count_of_edges.to_s
        puts "Длины сторон основания: " + @length_of_sides[0].to_s + ", " + @length_of_sides[1].to_s + ", " + @length_of_sides[2].to_s
        puts "--------------------------------"
    end

    def edit
    	puts "Что ты хочешь отредактировать?\n1. Высоту\n2. Длины сторон\n0. Ничего, я случайно сюда попал\n"
    	case gets.chomp.to_i
	    	when 1
	    		puts "Введи новую высоту: "
	    		@height = Prism.get_height
			when 2
				@length_of_sides = Prism.get_length_of_sides
			else
				puts "Выхожу"
		end
		calculate_square_of_base
		calculate_value
	end

	def show_menu
		end_it = false
		until end_it == true do
			puts "1. Показать информацию о призме\n2. Отредактировать параметры призмы\n0. Выход"
			case gets.chomp.to_i
				when 1
					get_info
				when 2
					edit
				when 0
					end_it = true
				else
					puts "Введи корректный номер"
			end
		end
	end
end

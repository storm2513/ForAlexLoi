import java.util.Scanner; 
import java.util.Arrays;


class Prism{
	double value, height, squareOfBase;
	int countOfEdges;
    double []lengthOfSides;

	public Prism(double height, double []lengthOfSides){
        this.height = height;
        this.lengthOfSides = Arrays.copyOf(lengthOfSides, lengthOfSides.length);
        this.squareOfBase = calculateSquareOfBase();
        this.value = calculateValue();
        this.countOfEdges = 5;
    }

    double calculateSquareOfBase(){
        double a = this.lengthOfSides[0], b = this.lengthOfSides[1], c = this.lengthOfSides[2];
        double halfPerimeter = (a + b + c) / 2.0;
        double square = Math.sqrt(halfPerimeter * (halfPerimeter - a) * (halfPerimeter - b) * (halfPerimeter - c));
        return square;
    }

    double calculateValue(){
        double value = this.squareOfBase * this.height;
        return value;
    }

    void getInfo(){
        System.out.println("--------------------------------");
        System.out.println("Объём -- " + this.value);
        System.out.println("Площадь основания -- " + this.squareOfBase);
        System.out.println("Высота -- " + this.height);
        System.out.println("Количество граней -- " + this.countOfEdges);
        System.out.println("Длины сторон основания: ");
        System.out.println(this.lengthOfSides[0] + ", " + this.lengthOfSides[1] + ", " + this.lengthOfSides[2]);
        System.out.println("--------------------------------");
    }

    void edit(){
        System.out.println("Что ты хочешь отредактировать?\n1. Высоту\n2. Длины сторон\n0. Ничего, я случайно сюда попал");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        switch(n){
            case 1:
                System.out.println("Введи новую высоту: ");
                this.height = getHeight();
                break;
            case 2:
                this.lengthOfSides = getLengthOfSides();
                break;
            case 0:
                break;
        }
        this.squareOfBase = calculateSquareOfBase();
        this.value = calculateValue();
    }

    void showMenu(){
        while(true){
            System.out.println("1. Показать информацию о призме\n2. Отредактировать параметры призмы\n0. Выход\n");
            Scanner sc = new Scanner(System.in);
	        int n = sc.nextInt();
            switch(n){
                case 1:
                    getInfo();
                    break;
                case 2:
                    edit();
                    break;
                case 0:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Введи корректный номер:");
                    break;
            }
        }
    }

    static double[] getLengthOfSides(){
	    boolean bad = true;
	    Scanner sc = new Scanner(System.in);
	    double[] lengthOfSides = new double[3];
	    while (bad){
	        for (int i = 0; i < 3; i++){
	            System.out.println("Введи " + (i + 1) + "-ую сторону: ");
	            lengthOfSides[i] = sc.nextDouble();
	        }
	        double a = lengthOfSides[0], b = lengthOfSides[1], c = lengthOfSides[2];
	        if((a > 0) && (b > 0) && (c > 0) && (a + b > c) && (b + c > a) && (c + a > b))
	            bad = false;
	        else
	            System.out.println("Треугольник с указанными сторонами не существует. Введи стороны заново: ");
	    }
	    return lengthOfSides;
	}

	static double getHeight(){
	    double height;
	    Scanner sc = new Scanner(System.in);
	    while(true){
	        height = sc.nextDouble();
	        if(height <= 0){
	            System.out.println("Введи корректную высоту:");
	        }
	        else
	            break;
	    }
	    return height;
	}



	public static void main(String args[]){
		double height;
	    double[] lengthOfSides;
	    System.out.println("Введи высоту призмы: ");
	    height = getHeight();
	    System.out.println("Отлично! Теперь введи стороны основания");
	    lengthOfSides = getLengthOfSides();
	    Prism myPrism = new Prism(height, lengthOfSides);
	    myPrism.showMenu();
	}
}
import java.util.Scanner;
public class Main
{
	public static void main(String[] args) {
		int[][] arr = new int[5][4];
		Scanner sc = new Scanner(System.in);
		double[] average = new double[5];
		for(int i=0;i<5;i++){
		    System.out.print("Enter roll Number : ");
		    arr[i][0] = sc.nextInt();
		    System.out.print("Enter Marks 1 : ");
		    arr[i][1] = sc.nextInt();
		    System.out.print("Enter Marks 2 : ");
		    arr[i][2] = sc.nextInt();
		    System.out.print("Enter Marks 3 : ");
		    arr[i][3] = sc.nextInt();
		    
		    average[i] = (arr[i][1]+arr[i][2]+arr[i][3])/3.0;
		}
		
		for(int i=0;i<5;i++){
		   System.out.printf("Roll -- %d  Marks 1 -- %d  Marks 2 -- %d  Marks 3 -- %d\nAverage -- %f\n",
		   arr[i][0],arr[i][1],arr[i][2],arr[i][0],average[i]);
		}
	}
}

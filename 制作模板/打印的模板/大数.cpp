///ƽ�����������������ʹ󸡵�����
/**�ڶ������У�2������ƽ��������sqrt(2)��
��һ������С��1.0110101000001001111...
����һ������n��һ��01��S�������������sqrt(n)��С������
����С����֮��Ĳ��֣����ҵ�S��һ�γ��ֵ�λ�á�
���sqrt(n)��������С�����ֿ��������޶��0��ɵ����С�
*/
import java.math.BigDecimal;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
			Scanner in = new Scanner(System.in);
			int T = 0 ;
			T = in.nextInt();
			while(T-- >0){
				int n = in.nextInt();
				String str = in.next();
				BigDecimal nn = new BigDecimal(n);
				n = (int) Math.sqrt(n);
				BigDecimal s = new BigDecimal(n);
				BigDecimal esp = new BigDecimal("0.1");
				int cnt=0;
				while(cnt <50){
					for(int i=1;i<10;i++){
						s = s.add(esp);
						if(s.multiply(s).compareTo(nn)>0){
							s = s.subtract(esp);
							break ;
						}else if(s.multiply(s).compareTo(nn)==0){
							break ;
						}
					}
					esp = esp.multiply(new BigDecimal("0.1"));
					cnt++ ;
				}
				String ans = "" ;
				s=s.subtract(new BigDecimal(n));
				for(int i=0;i<120;i++){
					s=s.multiply(new BigDecimal("2"));
					if(s.compareTo(new BigDecimal("1"))>=0){
						ans+="1";
						s = s.subtract(new BigDecimal("1"));
					}else{
						ans+="0";
					}
				}
				System.out.println(ans.indexOf(str));
			}
	}
}

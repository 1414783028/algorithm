bool isPalindromeNumber(long x)
{
   int a = x,h = 1;
   if(a < 0) return false;
   while(a/h >= 10)//�����
   {
     h*=10;//��h������a��ͬ��λ��
   }
   while(a > 0)
   {
	   if(a/h != a%10)
	   {
	     return false;
	   }
	   a = (a%h)/10;
	   h = h/100;
   }
   return true;
}
#include <stdio.h>
#include <conio.h>
#include <windows.h> // Olur da laz�m olur diye ekledim//
#include <time.h>
#include <stdlib.h>
#include <math.h>


												///////////7/* Muhammed Erkmen 040170049 */////////////

int k,j;     //Fonksiyondaki k ve j elemenalar�n� belirttim//


/* Matematiksel olarak tasarlad�m hocam oyunu 16x16 char arrayin c[x][y]si ile de yapt�m basit ve okuyan i�in hemen anla��l�r oldu. Ben de biraz amelelik yapt�m a��k�as� :p */ 



void printMap(int x,int y,int a, int b){	char map[17][35]=   //17 ve 35 boyutlar�nda bir dizi tan�mlay�p bu dizinin haritas�n� �izdim.//	
				{"._______________________________.\n",			//17 olmas�n�n sebebi en �stte bir s�n�r koyabilmek//
				"|_|_|_|_|_|_|_|_|W|_|_|_|_|_|_|_|\n",			//35 olmas�n�n sebebi ise 1den 31'e kadar olan karakterler hareket edilebilir bo�luklar, tam 16 adet.//
				"|_|_|_|_|_|_|_|_|W|_|_|_|_|_|_|_|\n",			// newline komutlar� da karakter say�ld���ndan bu kadar karakter vermem gerekiyordu//
	            "|_|_|W|_|_|_|_|_|_|_|_|_|_|W|_|_|\n",			// | ve _ karakterleri s�n�rlar� belirlerken, W karakterleri ise duvarlar� belirtiyor//
	            "|_|_|W|_|_|_|_|_|_|_|_|_|_|W|_|_|\n",
	            "|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|\n",
	        	"|_|_|_|_|_|_|W|W|W|_|_|_|_|_|_|_|\n",			// duvar koordinatlar�: (1,17)(2,17)(3,5)(3,27)(4,5)(4,27)(6,13)(6,15)(6,17) ->//
	            "|_|_|_|_|_|_|W|_|_|_|_|_|_|_|_|_|\n",			// (7,13)(9,21)(10,7)(10,9)(10,11)(11,11)(11,21)(12,21)(12,22)(15,3)(15,5)(15,7)//
	            "|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|\n",
	            "|_|_|_|_|_|_|_|_|_|_|W|_|_|_|_|_|\n",
	            "|_|_|_|W|W|W|_|_|_|_|W|_|_|_|_|_|\n",
	            "|_|_|_|_|_|W|_|_|_|_|W|_|_|_|_|_|\n",
	            "|_|_|_|_|_|_|_|_|_|_|W|W|_|_|_|_|\n",
	            "|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|\n",
	            "|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|\n",
	            "|_|W|W|W|_|_|_|_|_|_|_|_|_|_|_|_|\n",
	            "|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|\n",
	            };   			
	            				map[a][b]= '@';					//Fonksiyon kullan�l�rken yaz�lan a,b(polis i�in yaz�lacak px py diye) de�erlerinde @ karakteri ��karacaka//
    							map[x][y]= 'X';					//Fonksiyon kullan�l�rken yaz�lan x,y(h�rs�z i�in yaz�lacak tx ty diye) de�erlerinde X karakteri ��karacak//
    							map[8][31]= 'E';				//Fonksiyonun Escape point yani ka��� noktas�nda E karakterini yazacak//
								for (k=0;k<17; k++){			//Harita 2 boyutlu oldu�u i�in b�yle bir print komutuna ve bu d�ng�ye ihtiya� duydum//
    							for(j=0;j<34;j++){printf("%c",map[k][j]);}
    						
													}
}



	
//* Hocam �ncelikle kodlar� tamamen kendim yazd���m i�in a��klama c�mlelerini ingilizceye tam �evirebilmek i�in zaman ay�rmam gerekiyor bu y�zden t�rk�e yaz�yorum a��klamalar�//
//* Bu konudaki t�rl� de�erlendirmeniz kabulumdur benim i�in �nemli olan ne yapt���m� tam olarak anlatabilmek//


main()
{
	char zorluk,yon,oyunsonu,oyunsonu2;
	int tx,ty,px,py,a,b,c; //* Gerekli olan integerlar� girdim//
			
	basla1:		printf("Karakterler icin kurallara uygun rasgele sayilar hesaplaniyor. Lutfen bekleyiniz.\n Hicbir tusa dokunmayin. Gerekli sayilar bulundugunda ekran otomatik degisecektir.");
				srand(time(NULL));  //* Manhattan distance ve H�rs�z polis aras�ndaki mesafeyi sa�layan random say�lar.//
				tx=rand()%16+1;
				ty=(2*(rand()%16))+1;
				px=rand()%16+1;
				py=(2*(rand()%16))+1;
			while((((abs(tx-8)+abs((ty-32)/2))<16)||(abs(tx-px)+abs((ty-32)/2-(py-32)/2)<16))|| (tx==1 && ty==17)||(tx==2 && ty==17)||(tx==3 && ty==5)||(tx==4 && ty==5)||(tx==3 && ty==27)||(tx==4 && ty==27)|| 
			(tx==6 && ty==13) || (tx==7 && ty==13) || (ty==21 && tx==(9||10||11||12)) || (tx==6 && ty==15) || (tx==6 && ty==17) || 
			(tx==10 && ty==7) || (tx==10 && ty==9) || (tx==10 && ty==11) || (tx==11 && ty==11) || (tx==12 && ty==23) || ( tx==15 && ty==3) ||  ( tx==15 && ty==5) ||
			 ( tx==15 && ty==7) || (px==1 && py==17)||(px==2 && py==17)||(px==3 && py==5)||(px==4 && py==5)||(px==3 && py==27)||(px==4 && py==27)|| 
			(px==6 && py==13) || (px==7 && py==13) || (py==21 && px==(9||10||11||12)) || (px==6 && py==15) || (px==6 && py==17) || 
			(px==10 && py==7) || (px==10 && py==9) || (px==10 && py==11) || (px==11 && py==11) || (px==12 && py==23) || ( px==15 && py==3) ||  ( px==15 && py==5) ||
			 ( px==15 && py==7) 
		)  //* Manhattan distance ve H�rs�z polis aras�ndaki mesafeyi sa�layan d�ng�.//
	
			{
				srand(time(NULL));  
				tx=rand()%16+1;
				ty=(2*(rand()%16))+1;
				px=rand()%16+1;
				py=(2*(rand()%16))+1;
			
			}
			
			
							
	system("cls");
	printf("  .���������������������������������������������������������������������.\n");
	printf("  |		Kontroller WASD veya ok tuslariyla saglanir  		|\n");
	printf("  |	Eger duvara carparsaniz polis durmaz ve kovalamaya devam eder   |\n  |---------------------------------------------------------------------|\n");
	printf("  |		    Karakterlere uygun yerler bulundu  			|\n");					
	printf("  |	   Zorluk seviyesi secin(Kolay icin K, Zor icin Z)  		|\n"); 	
	printf("   ��������������������������������������������������������������������� \n");
	zorluk=_getch();	//Kullan�c�dan al�nan zorluk karakterini zorluk diye tan�mlad���m karaktere atayacak//
	system("cls");	
	printMap(tx,ty,px,py);		//Zorluk seviyesi se�ildikten sonra, direkt olarak random gelen koordinatlar�n g�r�lebilmesi i�in �nce Map'i ekrana yazd�r�r//			
	if(zorluk=='k'){ 
	for(;;)  // Kolay seviye i�in ana d�ng�//
	{
		yon= _getch(); //* Kullan�c�dan karakter alan getch fonksiyonunun de�erini yon karakterine aktard�m//
		system("cls"); //* Her hareketten sonra eski hareket silinecek//
		
		
		// W tusuyla yap�lacak hareketler//
		
		if(yon == 'w'||yon =='W'|| yon==72) //Alttaki ko�ullar duvarlar�n alt�ndan yukar� ve mapin d���na ��k�lmamas� i�in gereken ko�ullar||
		{ srand(time(NULL));
			a= rand()%2;		//* Random bir movement yapabilmek i�in random say�lar gerekliydi//
			b= rand()%2;
		  if(a==0)					//* Random say�ya g�re random hareketlerin kodlar�. Ko�ullar ise duvarlar�n i�erisinden ge�ilmemesi i�in duvar koordinatlar�na g�re yaz�ld�//
		  { 
		  	if((px==1)|| (px-1==2 && py==17) || (px-1==4 && py==5) || (px-1==4 && py==27) || (px-1==6 && py==17) || (px-1==6 && py==15) || (px-1==7 && py==13) ||
		    (px-1==10 && py==9) || (px-1==10 && py==7) || (px-1==11 && py==11) || (px-1==12 && py==23) || (px-1==12 && py==21) )
		    	px=px+1;
		   
		   else if((px==16) || (px==2 && py==5) || (px==2 && py==27) || (px==5 && py==13) || (px==5 && py==15) || (px==5 && py==17)||(px==8 && py==21)|| (px==9 && py==7)||(px==9 && py==9)
	       ||(px==9 && py==11) || (px==11 && py==23) || (px==14 && py==3) || (px==14 && py==5) || (px==14 && py==7)) 
		  		 px=px-1;
		    
			else {if(b==0) 
				 px=px+1;
				 if(b==1) 
				 px=px-1;}
		}
		  if(a==1)					//* Random say�ya g�re random hareketlerin kodlar�. Ko�ullar ise duvarlar�n i�erisinden ge�ilmemesi i�in duvar koordinatlar�na g�re yaz�ld�//
		  {if((py==31 || (px==15 && py==1) || (px==1 && py==15) || (px==2 && py==15) || (px==3 && py==3) || (px==4 && py==3) || (px==3 && py==25) || (px==4 && py==25)|| 
			(px==6 && py==11) || (px==7 && py==11) || (px==9 && py==19) || (px==10 && py==19) || (px==11 && py==19) || (px==12 && py==19) || (px==10 && py==5) || (px==11 && py==9) ))
			py=py-2;	//* E�er polisin sa��nda duvar varsa sola gidecek//
			
			else if((py==1)|| (px==1 && py==19) || (px==2 && py==19) || (px==3 && py==7) || (px==4 && py==7) || (px==3 && py==29) || (px==4 && py==29) || (px==6 && py==19) || 
		   (px==7 && py==15) || (px==9 && py==23) || (px==10 && py==23) || (px==11 && py==23) || (px==12 && py==25) || (px==10 && py==13) || (px==11 && py==13) || (px==15 && py==9))
			py=py+2;	//* E�er polisin solunda duvar varsa sa�a gidecek//
			
			else{if(b==0) py=py+2;		//* Random say�ya g�re random hareketlerin kodlar�. Ko�ullar ise duvarlar�n i�erisinden ge�ilmemesi i�in duvar koordinatlar�na g�re yaz�ld�//
				if(b==1)	py=py-2;}
		  }
		
		
		if((tx==1)|| (tx-1==2 && ty==17) || (tx-1==4 && ty==5) || (tx-1==4 && ty==27) || (tx-1==6 && ty==17) || (tx-1==6 && ty==15) || (tx-1==7 && ty==13) || (tx-1==10 && ty==9) || (tx-1==10 && ty==7) || (tx-1==11 && ty==11) || (tx-1==12 && ty==23) || (tx-1==12 && ty==21) || (tx-1==15 && ty==3) || (tx-1==15 && ty==5) || (tx-1==15 && ty==7))
		{printf("DUVARA TOSLADINIZ :)\n POLIS GELIYOR!\n");}
		else
		tx=tx-1;
		printMap(tx,ty,px,py);
		}
		
		
		// S Tusuyla yap�lacak hareketler //
		
		if(yon == 's'||yon =='S' || yon == 80)
		{	srand(time(NULL));
			a= rand()%2;
			b= rand()%2;
		  if(a==0)							//* Random say�ya g�re random hareketlerin kodlar�. Ko�ullar ise duvarlar�n i�erisinden ge�ilmemesi i�in duvar koordinatlar�na g�re yaz�ld�//
		  {	if((px==1)|| (px-1==2 && py==17) || (px-1==4 && py==5) || (px-1==4 && py==27) || (px-1==6 && py==17) || (px-1==6 && py==15) || (px-1==7 && py==13) ||
		  	 (px-1==10 && py==9) || (px-1==10 && py==7) || (px-1==11 && py==11) || (px-1==12 && py==23) || (px-1==12 && py==21) || (px-1==15 && py==3) || (px-1==15 && py==5) || 
		  	 (px-1==15 && py==7))
		  	   px=px+1;
		          else if((px==16) || (px==2 && py==5) || (px==2 && py==27) || (px==5 && py==13) || (px==5 && py==15) || (px==5 && py==17)||(px==8 && py==21)|| (px==9 && py==7)||(px==9 && py==9)
		            ||(px==9 && py==11) || (px==11 && py==23) || (px==14 && py==3) || (px==14 && py==5) || (px==14 && py==7)) 
		      	      px=px-1;
		               	else   {if(b==0) 
								px=px+1;
								if(b==1)
								px=px-1;}
		}
		  if(a==1)					//* Random say�ya g�re random hareketlerin kodlar�. Ko�ullar ise duvarlar�n i�erisinden ge�ilmemesi i�in duvar koordinatlar�na g�re yaz�ld�//
		  {if((py==31 || (px==15 && py==1) || (px==1 && py==15) || (px==2 && py==15) || (px==3 && py==3) || (px==4 && py==3) || (px==3 && py==25) || (px==4 && py==25)|| 
			(px==6 && py==11) || (px==7 && py==11) || (px==9 && py==19) || (px==10 && py==19) || (px==11 && py==19) || (px==12 && py==19) || (px==10 && py==5) || (px==11 && py==9) ))
			  py=py-2;
			     else if((py==1)|| (px==1 && py==19) || (px==2 && py==19) || (px==3 && py==7) || (px==4 && py==7) || (px==3 && py==29) || (px==4 && py==29) || (px==6 && py==19) || 
			     (px==7 && py==15) || (px==9 && py==23) || (px==10 && py==23) || (px==11 && py==23) || (px==12 && py==25) || (px==10 && py==13) || (px==11 && py==13) || (px==15 && py==9))
				   py=py+2;
					else{if(b==0) 
						 py=py+2;			//* Random say�ya g�re random hareketlerin kodlar�. Ko�ullar ise duvarlar�n i�erisinden ge�ilmemesi i�in duvar koordinatlar�na g�re yaz�ld�//
					     if(b==1)	
						 py=py-2;}		//* Random say�ya g�re random hareketlerin kodlar�. Ko�ullar ise duvarlar�n i�erisinden ge�ilmemesi i�in duvar koordinatlar�na g�re yaz�ld�//
		
		  }
		
		if(tx==16 || (tx==2 && ty==5) || (tx==2 && ty==27) || (tx==5 && ty==13) || (tx==5 && ty==15) || (tx==5 && ty==17)||(tx==8 && ty==21)|| (tx==9 && ty==7)||(tx==9 && ty==9)
		||(tx==9 && ty==11) || (tx==11 && ty==23) || (tx==14 && ty==3) || (tx==14 && ty==5) || (tx==14 && ty==7))	
		{		
				printf("DUVARA TOSLADINIZ :)\n POLIS GELIYOR! :)\n");	}
			else
			tx+=1;						//* E�er duvar yoksa h�rs�z�n bir a�a�� sat�ra ge�mesi i�in yaz�ld�//
			printMap(tx,ty,px,py);		//* Map yazd�r�ld�//
		}	
	

		// A Tusuyla yap�lacak Hareketler//
	
		if(yon == 'a'||yon =='A' || yon== 75)
		{ 	
		srand(time(NULL));
			a= rand()%2;		
			b= rand()%2;
		  if(a==0)				//* Random say�ya g�re random hareketlerin kodlar�. Ko�ullar ise duvarlar�n i�erisinden ge�ilmemesi i�in duvar koordinatlar�na g�re yaz�ld�//
		  {if((px==1)|| (px-1==2 && py==17) || (px-1==4 && py==5) || (px-1==4 && py==27) || (px-1==6 && py==17) || (px-1==6 && py==15) || (px-1==7 && py==13) ||
		   (px-1==10 && py==9) || (px-1==10 && py==7) || (px-1==11 && py==11) || (px-1==12 && py==23) || (px-1==12 && py==21) || (px-1==15 && py==3) || (px-1==15 && py==5) || 
		   (px-1==15 && py==7))
		   px=px+1;
		   		else if((px==16) || (px==2 && py==5) || (px==2 && py==27) || (px==5 && py==13) || (px==5 && py==15) || (px==5 && py==17)||(px==8 && py==21)|| (px==9 && py==7)||(px==9 && py==9)
				||(px==9 && py==11) || (px==11 && py==23) || (px==14 && py==3) || (px==14 && py==5) || (px==14 && py==7)) 
				px=px-1;
					else {  if(b==0) 
							px=px+1;
							if(b==1)
							px=px-1;}
		  }
		  if(a==1)			//* Random say�ya g�re random hareketlerin kodlar�. Ko�ullar ise duvarlar�n i�erisinden ge�ilmemesi i�in duvar koordinatlar�na g�re yaz�ld�//
		  {if((py==31 || (px==15 && py==1) || (px==1 && py==15) || (px==2 && py==15) || (px==3 && py==3) || (px==4 && py==3) || (px==3 && py==25) || (px==4 && py==25)|| 
			(px==6 && py==11) || (px==7 && py==11) || (px==9 && py==19) || (px==10 && py==19) || (px==11 && py==19) || (px==12 && py==19) || (px==10 && py==5) || (px==11 && py==9) ))
			py=py-2;
				else if((py==1)|| (px==1 && py==19) || (px==2 && py==19) || (px==3 && py==7) || (px==4 && py==7) || (px==3 && py==29) || (px==4 && py==29) || (px==6 && py==19) || 
				(px==7 && py==15) || (px==9 && py==23) || (px==10 && py==23) || (px==11 && py==23) || (px==12 && py==25) || (px==10 && py==13) || (px==11 && py==13) || (px==15 && py==9))
				py=py+2;
					else{if(b==0) 
						 py=py+2;			//* Random say�ya g�re random hareketlerin kodlar�. Ko�ullar ise duvarlar�n i�erisinden ge�ilmemesi i�in duvar koordinatlar�na g�re yaz�ld�//
						 if(b==1)	
						 py=py-2;}
								
		  }
		
		if( (ty==1)|| (tx==1 && ty==19) || (tx==2 && ty==19) || (tx==3 && ty==7) || (tx==4 && ty==7) || (tx==3 && ty==29) || (tx==4 && ty==29) || (tx==6 && ty==19) || 
		(tx==7 && ty==15) || (tx==9 && ty==23) || (tx==10 && ty==23) || (tx==11 && ty==23) || (tx==12 && ty==25) || (tx==10 && ty==13) || (tx==11 && ty==13) || (tx==15 && ty==9))
		{printf("DUVARA TOSLADINIZ :)\n POLIS GELIYOR! :)\n");}
		    else
			ty-=2;
			printMap(tx,ty,px,py);
		}
		
					//D Tusuyla yap�lacak hareketler//
			
		if(yon == 'd'||yon =='D' || yon==77)
		{
			srand(time(NULL));
			a= rand()%2;
			b= rand()%2;
		  if(a==0)
		  {if((px==1)|| (px-1==2 && py==17) || (px-1==4 && py==5) || (px-1==4 && py==27) || (px-1==6 && py==17) || (px-1==6 && py==15) || (px-1==7 && py==13) ||
		   (px-1==10 && py==9) || (px-1==10 && py==7) || (px-1==11 && py==11) || (px-1==12 && py==23) || (px-1==12 && py==21) || (px-1==15 && py==3) || (px-1==15 && py==5) || 
		   (px-1==15 && py==7))
		 	  px=px+1;
		   		else if((px==16) || (px==2 && py==5) || (px==2 && py==27) || (px==5 && py==13) || (px==5 && py==15) || (px==5 && py==17)||(px==8 && py==21)|| (px==9 && py==7)||(px==9 && py==9)
				||(px==9 && py==11) || (px==11 && py==23) || (px==14 && py==3) || (px==14 && py==5) || (px==14 && py==7)) 
					px=px-1;
					else {  if(b==0) 
							px=px+1;
							if(b==1) 
							px=px-1;}
		}
		  if(a==1)
		  {if((py==31 || (px==15 && py==1) || (px==1 && py==15) || (px==2 && py==15) || (px==3 && py==3) || (px==4 && py==3) || (px==3 && py==25) || (px==4 && py==25)|| 
			(px==6 && py==11) || (px==7 && py==11) || (px==9 && py==19) || (px==10 && py==19) || (px==11 && py==19) || (px==12 && py==19) || (px==10 && py==5) || (px==11 && py==9) ))
			py=py-2;
					else if((py==1)|| (px==1 && py==19) || (px==2 && py==19) || (px==3 && py==7) || (px==4 && py==7) || (px==3 && py==29) || (px==4 && py==29) || (px==6 && py==19) || 
					(px==7 && py==15) || (px==9 && py==23) || (px==10 && py==23) || (px==11 && py==23) || (px==12 && py==25) || (px==10 && py==13) || (px==11 && py==13) || (px==15 && py==9))
						py=py+2;
							else{if(b==0) 
								 py=py+2;
								 if(b==1)	
								 py=py-2;}
		  }	
		if( ty==31 || (tx==15 && ty==1) || (tx==1 && ty==15) || (tx==2 && ty==15) || (tx==3 && ty==3) || (tx==4 && ty==3) || (tx==3 && ty==25) || (tx==4 && ty==25)|| 
			(tx==6 && ty==11) || (tx==7 && ty==11) || (tx==9 && ty==19) || (tx==10 && ty==19) || (tx==11 && ty==19) || (tx==12 && ty==19) || (tx==10 && ty==5) || (tx==11 && ty==9)  ) 
		{		
				printf("DUVARA TOSLADINIZ :)\n POLIS GELIYOR! :)\n");	}					
			else 
		 	ty+=2;						
			printMap(tx,ty,px,py);}
		
		if((tx==px)&&(ty==py))
		printf("Kaybettiniz\n");
			
		if((tx==8 && ty==31))
		{
		printf("Tebrikler Kazandiniz. Tekrar baslamak icin T, cikmak icin C'ye basiniz\n");
		scanf("%c", &oyunsonu);
				basla2:
				if(oyunsonu=='t')
				{goto basla1;
				}
				else if(oyunsonu=='c')
				return 0;
				else printf("Yanlis tusa bastiniz");
			
							}	
		}	
	}
	//----------------------------------------------------------- ZOR MOD---------------------------------------------------------------------------------------------//
	else if(zorluk=='z'){for(;;)  // Zor seviye icin d�ng� //
	{
		yon= _getch(); //* Kullan�c�dan karakter alan getch fonksiyonunun de�erini yon karakterine aktard�m//
		system("cls"); //* Her hareketten sonra eski hareket silinecek//
		
		
				// W Tusunda kullan�lacak komutlar //
				
		if(yon == 'w'||yon =='W'|| yon==72) //Alttaki ko�ullar duvarlar�n alt�ndan yukar� ve mapin d���na ��k�lmamas� i�in gereken ko�ullar||
		{ 
		if(abs(tx-px)>=abs(((ty+1)/2)-((py+1)/2))){
		
		if(tx-px>0) 
		{ if((px+1==1 && py==17)||(px+1==2 && py==17)||(px+1==3 && py==5)||(px+1==4 && py==5)||(px+1==3 && py==27)||(px+1==4 && py==27)|| (px+1==6 && py==13) || (px+1==6 && py==15) || (px+1==6 && py==17) || (px+1==7 && py==13) || (py==21 && px+1==9) || (py==21 && px+1==10) || (py==21 && px+1==12) || (py==21 && px+1==11)
			|| (px+1==10 && py==7) || (px+1==10 && py==9) || (px+1==10 && py==11) || (px+1==11 && py==11) || (px+1==12 && py==23) || ( px+1==15 && py==3) ||  ( px+1==15 && py==5) ||  ( px+1==15 && py==7))
			 {
				if(py>=ty) 
				{	if((py==23 && px==11)) 
						py=py+2;
					else 
						py=py-2;
				}
				else
			 		py=py+2;
			 }
		  else 
			px=px+1;
		}
		
		if(tx-px<0)
		{	if((px-1==1 && py==17)||(px-1==2 && py==17)||(px-1==3 && py==5)||(px-1==4 && py==5)||(px-1==3 && py==27)||(px-1==4 && py==27)|| (px-1==6 && py==13) || (px-1==6 && py==15) || (px-1==6 && py==17) || (px-1==7 && py==13) || (py==21 && px-1==9) || (py==21 && px-1==10) || (py==21 && px-1==12) || (py==21 && px-1==11) 
			|| (px-1==10 && py==7) || (px==3 && py==15) || (px==12 && py==9) ||  (px-1==10 && py==9) || (px-1==10 && py==11) || (px-1==11 && py==11) || (px==3 && py==19)|| (px-1==12 && py==23) || ( px-1==15 && py==3) ||  ( px-1==15 && py==5) ||  ( px-1==15 && py==7))
			{	
					if(ty==py){
					px=px-1;
				
					}
				
				if(ty>py)
				{	if((px==11 && py==7)|| (px==11 && py==9) ){
				
						if((px==12 && py==9)) py=py+2;
						else px=px+1;}
					else 
						py=py+2;
			}
			if(py>ty){
				if((py==15 && px==7)|| (py==17 && px==7)) py=py+2;
				else py=py-2;
			}
			}
			else px=px-1;
		}
		}
								
	else{
		if(tx==px)
			{ 
			if(py>ty){
				if((px==1 && py-2==17)||(px==2 && py-2==17)||(px==3 && py-2==5)||(px==4 && py-2==5)||(px==3 && py-2==27)||(px==4 && py-2==27)|| (px==6 && py-2==13) || (px==6 && py-2==15) || (px==6 && py-2==17) || (px==7 && py-2==13) || (py-2==21 && px==9) || (py-2==21 && px==10) || (py-2==21 && px==12) || (py-2==21 && px==11) 
				|| (px==10 && py-2==7) || (px==10 && py-2==9) || (px==10 && py-2==11) || (px==11 && py-2==11) || (px==12 && py-2==23) || ( px==15 && py-2==3) ||  ( px==15 && py-2==5) ||  ( px==15 && py-2==7))
				px=px+1;
				else py=py-2;}
			if(py<ty)
			{
				if((px==1 && py+2==17)||(px==2 && py+2==17)||(px==3 && py+2==5)||(px==4 && py+2==5)||(px==3 && py+2==27)||(px==4 && py+2==27)|| (px==6 && py+2==13) || (px==6 && py+2==15) || (px==6 && py+2==17) || (px==7 && py+2==13) || (py+2==21 && px==9) || (py+2==21 && px==10) || (py+2==21 && px==12) || (py+2==21 && px==11) 
				|| (px==10 && py+2==7) || (px==10 && py+2==9) || (px==10 && py+2==11) || (px==11 && py+2==11) || (px==12 && py+2==23) || ( px==15 && py+2==3) ||  ( px==15 && py+2==5) ||  ( px==15 && py+2==7))
				px=px+1;
				else py=py+2;
			}
				 	}
		else{

			
			if(ty-py>0){
				if((px==1 && py+2==17)||(px==2 && py+2==17)||(px==3 && py+2==5)||(px==4 && py+2==5)||(px==3 && py+2==27)||(px==4 && py+2==27)|| (px==6 && py+2==13) || (px==6 && py+2==15) || (px==6 && py+2==17) || (px==7 && py+2==13) || (py+2==21 && px==9) || (py+2==21 && px==10) || (py+2==21 && px==12) || (py+2==21 && px==11) 
			|| (px==10 && py+2==7) || (px==10 && py+2==9) || (px==10 && py+2==11) || (px==11 && py+2==11) || (px==12 && py+2==23) || ( px==15 && py+2==3) ||  ( px==15 && py+2==5) ||  ( px==15 && py+2==7))
				{if(tx>px || (px==2 && py==15)) px=px+1;
					if(px>tx && ((px!=3 && py!=17) && (px!=2 && py!=17))) px=px-1;
				}
				else {if(px==7&&py==17) px=px-1;
						else py=py+2;
				}
				}
			if(ty-py<0) 
			{
				if((px==1 && py-2==17)||(px==2 && py-2==17)||(px==3 && py-2==5)||(px==4 && py-2==5)||(px==3 && py-2==27)||(px==4 && py-2==27)|| (px==6 && py-2==13) || (px==6 && py-2==15) || (px==6 && py-2==17) || (px==7 && py-2==13) || (py-2==21 && px==9) || (py-2==21 && px==10) || (py-2==21 && px==12) || (py-2==21 && px==11) 
				|| (px==10 && py-2==7) || (px==10 && py-2==9) || (px==10 && py-2==11) || (px==11 && py-2==11) || (px==12 && py-2==23) || ( px==15 && py-2==3) ||  ( px==15 && py-2==5) ||  ( px==15 && py-2==7))
					{if(tx>px || (px==2 && py==19)) px=px+1;
					if(tx<px &&(px!=2 && py!=19) &&(px!=3 && py!=19)) px=px-1;
					}
				else py=py-2;
			}
				}

		}
						if((tx==1)|| (tx-1==2 && ty==17) || (tx-1==4 && ty==5) || (tx-1==4 && ty==27) || (tx-1==6 && ty==17) || (tx-1==6 && ty==15) || (tx-1==7 && ty==13) || (tx-1==10 && ty==9) || (tx-1==10 && ty==7) || (tx-1==11 && ty==11) || (tx-1==12 && ty==23) || (tx-1==12 && ty==21) || (tx-1==15 && ty==3) || (tx-1==15 && ty==5) || (tx-1==15 && ty==7))
				{printf("DUVARA TOSLADINIZ :)\n POLIS GELIYOR!\n");}
					else
					tx=tx-1;
					printMap(tx,ty,px,py);
				
		}	
		
		
		
		
		if(yon == 's'||yon =='S' || yon==80)
		{	if(abs(tx-px)>=abs(((ty+1)/2)-((py+1)/2))){
		
		if(tx-px>0) 
		{ if((px+1==1 && py==17)||(px+1==2 && py==17)||(px+1==3 && py==5)||(px+1==4 && py==5)||(px+1==3 && py==27)||(px+1==4 && py==27)|| (px+1==6 && py==13) || (px+1==6 && py==15) || (px+1==6 && py==17) || (px+1==7 && py==13) || (py==21 && px+1==9) || (py==21 && px+1==10) || (py==21 && px+1==12) || (py==21 && px+1==11)
			|| (px+1==10 && py==7) || (px+1==10 && py==9) || (px+1==10 && py==11) || (px+1==11 && py==11) || (px+1==12 && py==23) || ( px+1==15 && py==3) ||  ( px+1==15 && py==5) ||  ( px+1==15 && py==7))
			 {
				if(py>=ty) 
				{	if((py==23 && px==11)) 
						py=py+2;
					else 
						py=py-2;
				}
				else
			 		py=py+2;
			 }
		  else 
			px=px+1;
		}
		
		if(tx-px<0)
		{	if((px-1==1 && py==17)||(px-1==2 && py==17)||(px-1==3 && py==5)||(px-1==4 && py==5)||(px-1==3 && py==27)||(px-1==4 && py==27)|| (px-1==6 && py==13) || (px-1==6 && py==15) || (px-1==6 && py==17) || (px-1==7 && py==13) || (py==21 && px-1==9) || (py==21 && px-1==10) || (py==21 && px-1==12) || (py==21 && px-1==11) 
			|| (px-1==10 && py==7) || (px==3 && py==15) || (px==12 && py==9) ||  (px-1==10 && py==9) || (px-1==10 && py==11) || (px-1==11 && py==11) || (px==3 && py==19)|| (px-1==12 && py==23) || ( px-1==15 && py==3) ||  ( px-1==15 && py==5) ||  ( px-1==15 && py==7))
			{	
					if(ty==py){
					px=px-1;
				
					}
				
				if(ty>py)
				{	if((px==11 && py==7)|| (px==11 && py==9) ){
				
						if((px==12 && py==9)) py=py+2;
						else px=px+1;}
					else 
						py=py+2;
			}
			if(py>ty){
				if((py==15 && px==7)|| (py==17 && px==7)) py=py+2;
				else py=py-2;
			}
			}
			else px=px-1;
		}
		}
								
	else{
		if(tx==px)
			{ 
			if(py>ty){
				if((px==1 && py-2==17)||(px==2 && py-2==17)||(px==3 && py-2==5)||(px==4 && py-2==5)||(px==3 && py-2==27)||(px==4 && py-2==27)|| (px==6 && py-2==13) || (px==6 && py-2==15) || (px==6 && py-2==17) || (px==7 && py-2==13) || (py-2==21 && px==9) || (py-2==21 && px==10) || (py-2==21 && px==12) || (py-2==21 && px==11) 
				|| (px==10 && py-2==7) || (px==10 && py-2==9) || (px==10 && py-2==11) || (px==11 && py-2==11) || (px==12 && py-2==23) || ( px==15 && py-2==3) ||  ( px==15 && py-2==5) ||  ( px==15 && py-2==7))
				px=px+1;
				else py=py-2;}
			if(py<ty)
			{
				if((px==1 && py+2==17)||(px==2 && py+2==17)||(px==3 && py+2==5)||(px==4 && py+2==5)||(px==3 && py+2==27)||(px==4 && py+2==27)|| (px==6 && py+2==13) || (px==6 && py+2==15) || (px==6 && py+2==17) || (px==7 && py+2==13) || (py+2==21 && px==9) || (py+2==21 && px==10) || (py+2==21 && px==12) || (py+2==21 && px==11) 
				|| (px==10 && py+2==7) || (px==10 && py+2==9) || (px==10 && py+2==11) || (px==11 && py+2==11) || (px==12 && py+2==23) || ( px==15 && py+2==3) ||  ( px==15 && py+2==5) ||  ( px==15 && py+2==7))
				px=px+1;
				else py=py+2;
			}
				 	}
		else{

			
			if(ty-py>0){
				if((px==1 && py+2==17)||(px==2 && py+2==17)||(px==3 && py+2==5)||(px==4 && py+2==5)||(px==3 && py+2==27)||(px==4 && py+2==27)|| (px==6 && py+2==13) || (px==6 && py+2==15) || (px==6 && py+2==17) || (px==7 && py+2==13) || (py+2==21 && px==9) || (py+2==21 && px==10) || (py+2==21 && px==12) || (py+2==21 && px==11) 
			|| (px==10 && py+2==7) || (px==10 && py+2==9) || (px==10 && py+2==11) || (px==11 && py+2==11) || (px==12 && py+2==23) || ( px==15 && py+2==3) ||  ( px==15 && py+2==5) ||  ( px==15 && py+2==7))
				{if(tx>px || (px==2 && py==15)) px=px+1;
					if(px>tx && ((px!=3 && py!=17) && (px!=2 && py!=17))) px=px-1;
				}
				else {if(px==7&&py==17) px=px-1;
						else py=py+2;
				}
				}
			if(ty-py<0) 
			{
				if((px==1 && py-2==17)||(px==2 && py-2==17)||(px==3 && py-2==5)||(px==4 && py-2==5)||(px==3 && py-2==27)||(px==4 && py-2==27)|| (px==6 && py-2==13) || (px==6 && py-2==15) || (px==6 && py-2==17) || (px==7 && py-2==13) || (py-2==21 && px==9) || (py-2==21 && px==10) || (py-2==21 && px==12) || (py-2==21 && px==11) 
				|| (px==10 && py-2==7) || (px==10 && py-2==9) || (px==10 && py-2==11) || (px==11 && py-2==11) || (px==12 && py-2==23) || ( px==15 && py-2==3) ||  ( px==15 && py-2==5) ||  ( px==15 && py-2==7))
					{if(tx>px || (px==2 && py==19)) px=px+1;
					if(tx<px &&(px!=2 && py!=19) &&(px!=3 && py!=19)) px=px-1;
					}
				else py=py-2;
			}
				}

		}
		if(tx==16 || (tx==2 && ty==5) || (tx==2 && ty==27) || (tx==5 && ty==13) || (tx==5 && ty==15) || (tx==5 && ty==17)||(tx==8 && ty==21)|| (tx==9 && ty==7)||(tx==9 && ty==9)
		||(tx==9 && ty==11) || (tx==11 && ty==23) || (tx==14 && ty==3) || (tx==14 && ty==5) || (tx==14 && ty==7))	
		{		
				printf("DUVARA TOSLADINIZ :)\n POLIS GELIYOR! :)\n");	}
		else
			tx+=1;						//* E�er duvar yoksa h�rs�z�n bir a�a�� sat�ra ge�mesi i�in yaz�ld�//
			printMap(tx,ty,px,py);	//* Map yazd�r�ld�//
		}	
	

	
	
		if(yon == 'a'||yon =='A' || yon==75)
		{ 	
	if(abs(tx-px)>=abs(((ty+1)/2)-((py+1)/2))){
		
		if(tx-px>0) 
		{ if((px+1==1 && py==17)||(px+1==2 && py==17)||(px+1==3 && py==5)||(px+1==4 && py==5)||(px+1==3 && py==27)||(px+1==4 && py==27)|| (px+1==6 && py==13) || (px+1==6 && py==15) || (px+1==6 && py==17) || (px+1==7 && py==13) || (py==21 && px+1==9) || (py==21 && px+1==10) || (py==21 && px+1==12) || (py==21 && px+1==11)
			|| (px+1==10 && py==7) || (px+1==10 && py==9) || (px+1==10 && py==11) || (px+1==11 && py==11) || (px+1==12 && py==23) || ( px+1==15 && py==3) ||  ( px+1==15 && py==5) ||  ( px+1==15 && py==7))
			 {
				if(py>=ty) 
				{	if((py==23 && px==11)) 
						py=py+2;
					else 
						py=py-2;
				}
				else
			 		py=py+2;
			 }
		  else 
			px=px+1;
		}
		
		if(tx-px<0)
		{	if((px-1==1 && py==17)||(px-1==2 && py==17)||(px-1==3 && py==5)||(px-1==4 && py==5)||(px-1==3 && py==27)||(px-1==4 && py==27)|| (px-1==6 && py==13) || (px-1==6 && py==15) || (px-1==6 && py==17) || (px-1==7 && py==13) || (py==21 && px-1==9) || (py==21 && px-1==10) || (py==21 && px-1==12) || (py==21 && px-1==11) 
			|| (px-1==10 && py==7) || (px==3 && py==15) || (px==12 && py==9) ||  (px-1==10 && py==9) || (px-1==10 && py==11) || (px-1==11 && py==11) || (px==3 && py==19)|| (px-1==12 && py==23) || ( px-1==15 && py==3) ||  ( px-1==15 && py==5) ||  ( px-1==15 && py==7))
			{	
					if(ty==py){
					px=px-1;
				
					}
				
				if(ty>py)
				{	if((px==11 && py==7)|| (px==11 && py==9) ){
				
						if((px==12 && py==9)) py=py+2;
						else px=px+1;}
					else 
						py=py+2;
			}
			if(py>ty){
				if((py==15 && px==7)|| (py==17 && px==7)) py=py+2;
				else py=py-2;
			}
			}
			else px=px-1;
		}
		}
								
	else{
		if(tx==px)
			{ 
			if(py>ty){
				if((px==1 && py-2==17)||(px==2 && py-2==17)||(px==3 && py-2==5)||(px==4 && py-2==5)||(px==3 && py-2==27)||(px==4 && py-2==27)|| (px==6 && py-2==13) || (px==6 && py-2==15) || (px==6 && py-2==17) || (px==7 && py-2==13) || (py-2==21 && px==9) || (py-2==21 && px==10) || (py-2==21 && px==12) || (py-2==21 && px==11) 
				|| (px==10 && py-2==7) || (px==10 && py-2==9) || (px==10 && py-2==11) || (px==11 && py-2==11) || (px==12 && py-2==23) || ( px==15 && py-2==3) ||  ( px==15 && py-2==5) ||  ( px==15 && py-2==7))
				px=px+1;
				else py=py-2;}
			if(py<ty)
			{
				if((px==1 && py+2==17)||(px==2 && py+2==17)||(px==3 && py+2==5)||(px==4 && py+2==5)||(px==3 && py+2==27)||(px==4 && py+2==27)|| (px==6 && py+2==13) || (px==6 && py+2==15) || (px==6 && py+2==17) || (px==7 && py+2==13) || (py+2==21 && px==9) || (py+2==21 && px==10) || (py+2==21 && px==12) || (py+2==21 && px==11) 
				|| (px==10 && py+2==7) || (px==10 && py+2==9) || (px==10 && py+2==11) || (px==11 && py+2==11) || (px==12 && py+2==23) || ( px==15 && py+2==3) ||  ( px==15 && py+2==5) ||  ( px==15 && py+2==7))
				px=px+1;
				else py=py+2;
			}
				 	}
		else{

			
			if(ty-py>0){
				if((px==1 && py+2==17)||(px==2 && py+2==17)||(px==3 && py+2==5)||(px==4 && py+2==5)||(px==3 && py+2==27)||(px==4 && py+2==27)|| (px==6 && py+2==13) || (px==6 && py+2==15) || (px==6 && py+2==17) || (px==7 && py+2==13) || (py+2==21 && px==9) || (py+2==21 && px==10) || (py+2==21 && px==12) || (py+2==21 && px==11) 
			|| (px==10 && py+2==7) || (px==10 && py+2==9) || (px==10 && py+2==11) || (px==11 && py+2==11) || (px==12 && py+2==23) || ( px==15 && py+2==3) ||  ( px==15 && py+2==5) ||  ( px==15 && py+2==7))
				{if(tx>px || (px==2 && py==15)) px=px+1;
					if(px>tx && ((px!=3 && py!=17) && (px!=2 && py!=17))) px=px-1;
				}
				else {if(px==7&&py==17) px=px-1;
						else py=py+2;
				}
				}
			if(ty-py<0) 
			{
				if((px==1 && py-2==17)||(px==2 && py-2==17)||(px==3 && py-2==5)||(px==4 && py-2==5)||(px==3 && py-2==27)||(px==4 && py-2==27)|| (px==6 && py-2==13) || (px==6 && py-2==15) || (px==6 && py-2==17) || (px==7 && py-2==13) || (py-2==21 && px==9) || (py-2==21 && px==10) || (py-2==21 && px==12) || (py-2==21 && px==11) 
				|| (px==10 && py-2==7) || (px==10 && py-2==9) || (px==10 && py-2==11) || (px==11 && py-2==11) || (px==12 && py-2==23) || ( px==15 && py-2==3) ||  ( px==15 && py-2==5) ||  ( px==15 && py-2==7))
					{if(tx>px || (px==2 && py==19)) px=px+1;
					if(tx<px &&(px!=2 && py!=19) &&(px!=3 && py!=19)) px=px-1;
					}
				else py=py-2;
			}
				}

		}
		
		if( (ty==1)|| (tx==1 && ty==19) || (tx==2 && ty==19) || (tx==3 && ty==7) || (tx==4 && ty==7) || (tx==3 && ty==29) || (tx==4 && ty==29) || (tx==6 && ty==19) || 
		(tx==7 && ty==15) || (tx==9 && ty==23) || (tx==10 && ty==23) || (tx==11 && ty==23) || (tx==12 && ty==25) || (tx==10 && ty==13) || (tx==11 && ty==13) || (tx==15 && ty==9))
		{		
				printf("DUVARA TOSLADINIZ :)\n POLIS GELIYOR! :)\n");	}
		else
				ty-=2;
				printMap(tx,ty,px,py);
		}
		
		if(yon == 'd'||yon =='D' || yon==77)
		{
			if(abs(tx-px)>=abs(((ty+1)/2)-((py+1)/2))){
		
		if(tx-px>0) 
		{ if((px+1==1 && py==17)||(px+1==2 && py==17)||(px+1==3 && py==5)||(px+1==4 && py==5)||(px+1==3 && py==27)||(px+1==4 && py==27)|| (px+1==6 && py==13) || (px+1==6 && py==15) || (px+1==6 && py==17) || (px+1==7 && py==13) || (py==21 && px+1==9) || (py==21 && px+1==10) || (py==21 && px+1==12) || (py==21 && px+1==11)
			|| (px+1==10 && py==7) || (px+1==10 && py==9) || (px+1==10 && py==11) || (px+1==11 && py==11) || (px+1==12 && py==23) || ( px+1==15 && py==3) ||  ( px+1==15 && py==5) ||  ( px+1==15 && py==7))
			 {
				if(py>=ty) 
				{	if((py==23 && px==11)) 
						py=py+2;
					else 
						py=py-2;
				}
				else
			 		py=py+2;
			 }
		  else 
			px=px+1;
		}
		
		if(tx-px<0)
		{	if((px-1==1 && py==17)||(px-1==2 && py==17)||(px-1==3 && py==5)||(px-1==4 && py==5)||(px-1==3 && py==27)||(px-1==4 && py==27)|| (px-1==6 && py==13) || (px-1==6 && py==15) || (px-1==6 && py==17) || (px-1==7 && py==13) || (py==21 && px-1==9) || (py==21 && px-1==10) || (py==21 && px-1==12) || (py==21 && px-1==11) 
			|| (px-1==10 && py==7) || (px==3 && py==15) || (px==12 && py==9) ||  (px-1==10 && py==9) || (px-1==10 && py==11) || (px-1==11 && py==11) || (px==3 && py==19)|| (px-1==12 && py==23) || ( px-1==15 && py==3) ||  ( px-1==15 && py==5) ||  ( px-1==15 && py==7))
			{	
					if(ty==py){
					px=px-1;
				
					}
				
				if(ty>py)
				{	if((px==11 && py==7)|| (px==11 && py==9) ){
				
						if((px==12 && py==9)) py=py+2;
						else px=px+1;}
					else 
						py=py+2;
			}
			if(py>ty){
				if((py==15 && px==7)|| (py==17 && px==7)) py=py+2;
				else py=py-2;
			}
			}
			else px=px-1;
		}
		}
								
	else{
		if(tx==px)
			{ 
			if(py>ty){
				if((px==1 && py-2==17)||(px==2 && py-2==17)||(px==3 && py-2==5)||(px==4 && py-2==5)||(px==3 && py-2==27)||(px==4 && py-2==27)|| (px==6 && py-2==13) || (px==6 && py-2==15) || (px==6 && py-2==17) || (px==7 && py-2==13) || (py-2==21 && px==9) || (py-2==21 && px==10) || (py-2==21 && px==12) || (py-2==21 && px==11) 
				|| (px==10 && py-2==7) || (px==10 && py-2==9) || (px==10 && py-2==11) || (px==11 && py-2==11) || (px==12 && py-2==23) || ( px==15 && py-2==3) ||  ( px==15 && py-2==5) ||  ( px==15 && py-2==7))
				px=px+1;
				else py=py-2;}
			if(py<ty)
			{
				if((px==1 && py+2==17)||(px==2 && py+2==17)||(px==3 && py+2==5)||(px==4 && py+2==5)||(px==3 && py+2==27)||(px==4 && py+2==27)|| (px==6 && py+2==13) || (px==6 && py+2==15) || (px==6 && py+2==17) || (px==7 && py+2==13) || (py+2==21 && px==9) || (py+2==21 && px==10) || (py+2==21 && px==12) || (py+2==21 && px==11) 
				|| (px==10 && py+2==7) || (px==10 && py+2==9) || (px==10 && py+2==11) || (px==11 && py+2==11) || (px==12 && py+2==23) || ( px==15 && py+2==3) ||  ( px==15 && py+2==5) ||  ( px==15 && py+2==7))
				px=px+1;
				else py=py+2;
			}
				 	}
		else{

			
			if(ty-py>0){
				if((px==1 && py+2==17)||(px==2 && py+2==17)||(px==3 && py+2==5)||(px==4 && py+2==5)||(px==3 && py+2==27)||(px==4 && py+2==27)|| (px==6 && py+2==13) || (px==6 && py+2==15) || (px==6 && py+2==17) || (px==7 && py+2==13) || (py+2==21 && px==9) || (py+2==21 && px==10) || (py+2==21 && px==12) || (py+2==21 && px==11) 
			|| (px==10 && py+2==7) || (px==10 && py+2==9) || (px==10 && py+2==11) || (px==11 && py+2==11) || (px==12 && py+2==23) || ( px==15 && py+2==3) ||  ( px==15 && py+2==5) ||  ( px==15 && py+2==7))
				{if(tx>px || (px==2 && py==15)) px=px+1;
					if(px>tx && ((px!=3 && py!=17) && (px!=2 && py!=17))) px=px-1;
				}
				else {if(px==7&&py==17) px=px-1;
						else py=py+2;
				}
				}
			if(ty-py<0) 
			{
				if((px==1 && py-2==17)||(px==2 && py-2==17)||(px==3 && py-2==5)||(px==4 && py-2==5)||(px==3 && py-2==27)||(px==4 && py-2==27)|| (px==6 && py-2==13) || (px==6 && py-2==15) || (px==6 && py-2==17) || (px==7 && py-2==13) || (py-2==21 && px==9) || (py-2==21 && px==10) || (py-2==21 && px==12) || (py-2==21 && px==11) 
				|| (px==10 && py-2==7) || (px==10 && py-2==9) || (px==10 && py-2==11) || (px==11 && py-2==11) || (px==12 && py-2==23) || ( px==15 && py-2==3) ||  ( px==15 && py-2==5) ||  ( px==15 && py-2==7))
					{if(tx>px || (px==2 && py==19)) px=px+1;
					if(tx<px &&(px!=2 && py!=19) &&(px!=3 && py!=19)) px=px-1;
					}
				else py=py-2;
			}
				}

		}
		if( ty==31 || (tx==15 && ty==1) || (tx==1 && ty==15) || (tx==2 && ty==15) || (tx==3 && ty==3) || (tx==4 && ty==3) || (tx==3 && ty==25) || (tx==4 && ty==25)|| 
			(tx==6 && ty==11) || (tx==7 && ty==11) || (tx==9 && ty==19) || (tx==10 && ty==19) || (tx==11 && ty==19) || (tx==12 && ty==19) || (tx==10 && ty==5) || (tx==11 && ty==9)  ) 
		{		
				printf("DUVARA TOSLADINIZ :)\n POLIS GELIYOR! :)\n");	}					
		else 
		 ty+=2;						
			printMap(tx,ty,px,py);}
			if((tx==px)&&(ty==py))
		{printf("Kaybettiniz. Tekrar oynamak icin T, cikmak icin C'ye basiniz'\n");
			scanme2:		oyunsonu2=_getch();
				if(oyunsonu2=='t')
				goto basla1;
				else if(oyunsonu2=='c') return 0;
				else{
				printf("Hatali tus girimi. Lutfen tekrar deneyin.\n");
				
				goto scanme2;}

	}
		if((tx==8 && ty==31))
		{
		printf("Tebrikler Kazandiniz. Tekrar baslamak icin T, cikmak icin C'ye basiniz\n");
			scanme:	scanf("%c", &oyunsonu);
				if(oyunsonu=='t')
				goto basla1;
				else if(oyunsonu=='c') return 0;
				else{
				printf("Hatali tus girimi. Tekrar deneyin.\n");
				goto scanme;}
			
	
		}
		
}
}
}


		






	
	

	


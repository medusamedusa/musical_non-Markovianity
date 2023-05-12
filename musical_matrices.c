#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 7

//varia a seconda del numero di note della sequenza in esame. Da cambiare manualmente, come il nome dei file

//da ripetere per ogni sequenza


int main() {
	
	float frequency[N], start[N], duration[N], intensity[N], delta_frequency[N], delta_start[N], delta_duration[N], delta_intensity[N]; //mettere come double. &lf?
	float somma_freq, somma_start, somma_duration, somma_intensity, mean_value_frequency, mean_value_start, mean_value_duration, mean_value_intensity;			
 	
	int i,j;
	
	FILE *file_dati_entrata;
	FILE *file_dati_uscita_frequency_start;
	FILE *file_dati_uscita_frequency_duration;
	FILE *file_dati_uscita_frequency_intensity;
	FILE *file_dati_uscita_duration_intensity;
	FILE *file_dati_uscita_start_intensity;
	
	
	file_dati_entrata = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/prova_casi_limite/memoria_min_1.txt","r");
	file_dati_uscita_frequency_start = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/prova_casi_limite/memoria_min_frequency_start_1.txt","w");
	file_dati_uscita_frequency_duration = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/prova_casi_limite/memoria_min_frequency_duration_1.txt","w");
	file_dati_uscita_frequency_intensity = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/prova_casi_limite/memoria_min_frequency_intensity_1.txt","w");
	file_dati_uscita_duration_intensity = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/prova_casi_limite/memoria_min_duration_intensity_1.txt","w");
	file_dati_uscita_start_intensity = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/nprova_casi_limite/memoria_min_start_intensity_1.txt","w");
	
//	file_dati_entrata = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/numeri_GLASS/dati_Glass/Glass_12.txt","r");
//	file_dati_uscita_frequency_start = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/numeri_GLASS/matrici_Glass/Glass_frequency_start_12.txt","w");
//	file_dati_uscita_frequency_duration = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/numeri_GLASS/matrici_Glass/Glass_frequency_duration_12.txt","w");
//	file_dati_uscita_frequency_intensity = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/numeri_GLASS/matrici_Glass/Glass_frequency_intensity_12.txt","w");
//	file_dati_uscita_duration_intensity = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/numeri_GLASS/matrici_Glass/Glass_duration_intensity_12.txt","w");
//	file_dati_uscita_start_intensity = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/numeri_GLASS/matrici_Glass/Glass_start_intensity_12.txt","w");
	
	
//	file_dati_entrata = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/dati_Bellini/Bellini_16.txt","r");
//	file_dati_uscita_frequency_start = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/matrici_Bellini/Bellini_matrice_frequency_start_16.txt","w");
//	file_dati_uscita_frequency_duration = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/matrici_Bellini/Bellini_matrice_frequency_duration_16.txt","w");
//	file_dati_uscita_frequency_intensity = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/matrici_Bellini/Bellini_matrice_frequency_intensity_16.txt","w");
//	file_dati_uscita_duration_intensity = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/matrici_Bellini/Bellini_matrice_duration_intensity_16.txt","w");
//	file_dati_uscita_start_intensity = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/matrici_Bellini/Bellini_matrice_start_intensity_16.txt","w");
	
//	file_dati_entrata = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/dati_Maderna/Maderna_2.txt","r");
//	file_dati_uscita_frequency_start = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/matrici_Maderna/Maderna_matrice_frequency_start_2.txt","w");
//	file_dati_uscita_frequency_duration = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/matrici_Maderna/Maderna_matrice_frequency_duration_2.txt","w");
//	file_dati_uscita_frequency_intensity = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/matrici_Maderna/Maderna_matrice_frequency_intensity_2.txt","w");
//	file_dati_uscita_duration_intensity = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/matrici_Maderna/Maderna_matrice_duration_intensity_2.txt","w");
//	file_dati_uscita_start_intensity = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/matrici_Maderna/Maderna_matrice_start_intensity_2.txt","w");
	
	
//	file_dati_entrata = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/dati_Bellini_periodi/Bellini_frase_7.txt","r");
//	file_dati_uscita_frequency_start = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/matrici_Bellini_periodi/Bellini_matrice_frequency_start_frase_7.txt","w");
//	file_dati_uscita_frequency_duration = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/matrici_Bellini_periodi/Bellini_matrice_frequency_duration_frase_7.txt","w");
//	file_dati_uscita_frequency_intensity = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/matrici_Bellini_periodi/Bellini_matrice_frequency_intensity_frase_7.txt","w");
//	file_dati_uscita_duration_intensity = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/matrici_Bellini_periodi/Bellini_matrice_duration_intensity_frase_7.txt","w");
//	file_dati_uscita_start_intensity = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/matrici_Bellini_periodi/Bellini_matrice_start_intensity_frase_7.txt","w");

	
//	file_dati_entrata = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/dati_Maderna_correzione/Maderna_10.txt","r");
//	file_dati_uscita_frequency_start = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/matrici_Maderna_correzione/Maderna_matrice_frequency_start_10.txt","w");
//	file_dati_uscita_frequency_duration = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/matrici_Maderna_correzione/Maderna_matrice_frequency_duration_10.txt","w");
//	file_dati_uscita_frequency_intensity = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/matrici_Maderna_correzione/Maderna_matrice_frequency_intensity_10.txt","w");
//	file_dati_uscita_duration_intensity = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/matrici_Maderna_correzione/Maderna_matrice_duration_intensity_10.txt","w");
//	file_dati_uscita_start_intensity = fopen("/Users/mariamannone/Desktop/Programma_MatriciMusica/matrici_Maderna_correzione/Maderna_matrice_start_intensity_10.txt","w");
	
	
	//legge da un file i dati di partenza per la sequenza in esame,
	//e scrive su un altro file le matrici risultanti.

	
	/* Acquisizione dati */
	 
	
	for(i=0; i<N; i++) {
		fscanf(file_dati_entrata, "%f\t%f\t%f\t%f", &frequency[i], &start[i], &duration[i], &intensity[i]);
	}
	
	printf("\nfrequenze\tstart\t\tdurate\tintensita'\n");
	
	for(i=0; i<N; i++) {
		printf("%f\t%f\t%f\t%f\n", frequency[i], start[i], duration[i], intensity[i]);
	}
	
	printf("\n");
	
	 
	 //Inserimento manuale dei dati
	
	/*
	printf("Inserisci i valori di frequenza:\n"); 
	for(i=0;i<N;i++) {
		scanf ("%f",&frequency[i]);
	}
	
	for(i=0;i<N;i++) {
		printf("frequenza[%i] = %f\n", i, frequency[i]);
	}
	
	printf("Inserisci i valori di start:\n");
	for(i=0;i<N;i++) {
		scanf ("%f",&start[i]);
	}
	
	for(i=0;i<N;i++) {
		printf("start[%d] = %f\n", i, start[i]);
	}
	
	printf("Inserisci i valori di durata:\n");
	for(i=0;i<N;i++) {
		scanf ("%f",&duration[i]);
	}
	
	for(i=0;i<N;i++) {
		printf("durata[%d] = %f\n", i, duration[i]);
	}
	
	printf("Inserisci i valori di intensità:\n");
	for(i=0;i<N;i++) {
		scanf ("%f",&intensity[i]);
	}
	
	for(i=0;i<N;i++) {
		printf("intensità[%d] = %f\n", i, intensity[i]);
	}
	
	*/
	
	
	/* Calcolo dei valori medi */
	
	
	for(i=0;i<N;i++) {
		
		somma_freq+=frequency[i];
	}
	
	somma_start=0.;
	
	for(i=0;i<N;i++){
		somma_start+=start[i];
	}
	
	for(i=0;i<N;i++){
		somma_duration+=duration[i];
	}
	
	somma_intensity=0.;
	
	for(i=0;i<N;i++){
		somma_intensity+=intensity[i];
	}
	
	mean_value_frequency=somma_freq/N;
	mean_value_start=somma_start/N;
	mean_value_duration=somma_duration/N;
	mean_value_intensity=somma_intensity/N;

	printf("valor medio delle frequenze: %f\n", mean_value_frequency);
	printf("valor medio dei tempi di start: %f\n", mean_value_start);
	printf("valor medio delle durate: %f\n", mean_value_duration);
	printf("valor medio delle intensità: %f\n", mean_value_intensity);
	
	
	printf("\n\nFREQUENZE. Distanze dai valori medi:\n");
	
	for (i=0;i<N;i++) {
		
		delta_frequency[i]=sqrt((frequency[i]-mean_value_frequency)*(frequency[i]-mean_value_frequency));
	
	}
	

	
	
	//ordino in ordine crescente salvando i valori in un altri vettore, e poi divido i diversi vettori (quelli giusti) per il valore massimo.
	

	
	/* NORMALIZZAZIONE FREQUENZE */
	
	float delta_frequency_max,delta_frequency_min;
	
	float vettore_prova_delta_frequency[N];
	
	for(i=0;i<N;i++) {
		
		vettore_prova_delta_frequency[i]=delta_frequency[i];  //così creo un vettore nuovo con i valori di delta frequenze, che però conservo
																//nell'ordine giusto
		
	}

	float vettore;
	
	for(i=0;i<N;i++) {
		
		for(j=0;j<N-1;j++) {
			
			if(vettore_prova_delta_frequency[j]>vettore_prova_delta_frequency[j+1]) {
				vettore = vettore_prova_delta_frequency[j];
				vettore_prova_delta_frequency[j]=vettore_prova_delta_frequency[j+1];
				vettore_prova_delta_frequency[j+1]=vettore;
			}
			//ordine crescente
			
		}
		
		
	}
	
	//così l'ultimo vettore, l'N-esimo, sarà il più grande.
	//il primo sarà il più piccolo.
	
	
	for(i=0;i<N;i++) {
		
		printf("ordine dei vettori di prova: %f\n",vettore_prova_delta_frequency[i]);
		
	}
	
	
	delta_frequency_max=vettore_prova_delta_frequency[N-1];  //associa il valore più grande a delta_frequency_max
	
	delta_frequency_min=vettore_prova_delta_frequency[0];  //associa il valore più piccolo a delta_frequency_min
	
	printf("delta frequency min = %f\tdelta frequency max = %f\n\n",delta_frequency_min,delta_frequency_max);
	
	
	
	float delta_frequency_norm[i];
	
	if(delta_frequency_max==delta_frequency_min)
	{
		for(i=0;i<N;i++) {
			delta_frequency_norm[i]=delta_frequency[i]; //così, se i valori sono costanti e tutte le delta zero,
														// non si pone il problema della divisione per zero quando normalizzo
			printf("delta frequenze normalizzate %d = %f\n",i, delta_frequency_norm[i]);
		}
	}

	else {
		delta_frequency_norm[0]=(delta_frequency[0]-delta_frequency_min)/(delta_frequency_max-delta_frequency_min);
		printf("delta frequency min (0) = %f\n\n",delta_frequency[0]);  //stampato per controllare il metodo
		
		for(i=0;i<N;i++) {
			delta_frequency_norm[i]=(delta_frequency[i]-delta_frequency_min)/(delta_frequency_max-delta_frequency_min);
			printf("delta frequenze normalizzate %d = %f\n",i, delta_frequency_norm[i]);
			
		}
	}		
	
	
		
	

	/*
	 
	 
	 ALTRO METODO PER NORMALIZZARE: (resta però il potenziale problema della divisione per zero, qualora sia il massimo)
	 
	 
	 delta_frequency_max=vettore_prova_delta_frequency[N];  //associa il valore più grande a delta_frequency_max
	
	for(i=0;i<N;i++) {
		
		delta_frequency[i]=	delta_frequency[i]/delta_frequency_max;
		printf("delta frequenze %d = %f\n",i, delta_frequency[i]);
	}
	 
	 */
	
	
		
	
	printf("\n\nSTART. Distanze dai valori medi:\n");
	
	for (i=0;i<N;i++) {
		
		//delta_start[i]=sqrt((start[i]-mean_value_start)*(start[i]-mean_value_start))/((start[i]+mean_value_start)*(start[i]+mean_value_start));
		
		delta_start[i]=sqrt((start[i]-mean_value_start)*(start[i]-mean_value_start));
		
	}
	
	
	
	
	/* NORMALIZZAZIONE START */
	
	float delta_start_max, delta_start_min;
	
	float vettore_prova_delta_start[N];
	
	for(i=0;i<N;i++) {
		
		vettore_prova_delta_start[i]=delta_start[i];  //così creo un vettore nuovo con i valori di delta start, che però conservo
		//nell'ordine giusto
		
	}
	
	
	
	 for(i=0;i<N;i++) {   //attenzione, utilizzo qui "vettore" che però ha valori diversi rispetto a prima
		
		for(j=0;j<N-1;j++) {
			
			if(vettore_prova_delta_start[j]>vettore_prova_delta_start[j+1]) {
				vettore = vettore_prova_delta_start[j];
				vettore_prova_delta_start[j]=vettore_prova_delta_start[j+1];
				vettore_prova_delta_start[j+1]=vettore;
			}
			//ordine crescente
			
		}
		
		
	}
	
	//così l'ultimo vettore, l'N-esimo, sarà il più grande.
	
	
	for(i=0;i<N;i++) {
		
		printf("ordine dei vettori di prova: %f\n",vettore_prova_delta_start[i]);
		
	}
	
	
	delta_start_max=vettore_prova_delta_start[N-1];
	
	delta_start_min=vettore_prova_delta_start[0];
	
	

	
	printf("delta start min = %f\tdelta start max = %f\n\n",delta_start_min,delta_start_max);
	
	float delta_start_norm[i];
	
	if(delta_start_max==delta_start_min) {
		
		for(i=0;i<N;i++) {
			delta_start_norm[i]=delta_start[i];
		}
	}
	else {
		delta_start_norm[0]=(delta_start[0]-delta_start_min)/(delta_start_max-delta_start_min);
		printf("delta start min (0) = %f\n\n",delta_start[0]);  //stampato per controllare il metodo
		
		
		for(i=0;i<N;i++) {
			delta_start_norm[i]=(delta_start[i]-delta_start_min)/(delta_start_max-delta_start_min);
			printf("delta start %d = %f\n",i, delta_start_norm[i]);
			
		}
	}
	

	
	printf("\n\nDURATE. Distanze dai valori medi:\n");
	
	for (i=0;i<N;i++) {
		
		//delta_duration[i]=sqrt((duration[i]-mean_value_duration)*(duration[i]-mean_value_duration))/((duration[i]+mean_value_duration)*(duration[i]+mean_value_duration));
		
		delta_duration[i]=sqrt((duration[i]-mean_value_duration)*(duration[i]-mean_value_duration));
		
		printf("delta durate %d = %f\n",i, delta_duration[i]);
		
	}
	
	
	
	
	/* NORMALIZZAZIONE DURATE */
	
	float delta_duration_max, delta_duration_min;
	
	float vettore_prova_delta_duration[N];
	
	for(i=0;i<N;i++) {
		
		vettore_prova_delta_duration[i]=delta_duration[i];  //così creo un vettore nuovo con i valori di delta duration, che però conservo
		//nell'ordine giusto
		
	}
	
	
	for(i=0;i<N;i++) {   //attenzione, utilizzo qui "vettore" che però ha valori diversi rispetto a prima
		
		for(j=0;j<N-1;j++) {
			
			if(vettore_prova_delta_duration[j]>vettore_prova_delta_duration[j+1]) {
				vettore = vettore_prova_delta_duration[j];
				vettore_prova_delta_duration[j]=vettore_prova_delta_duration[j+1];
				vettore_prova_delta_duration[j+1]=vettore;
			}
			//ordine crescente
			
		}
		
		
	}
	
	//così l'ultimo vettore, l'N-esimo, sarà il più grande.
	
	
	for(i=0;i<N;i++) {
		
		printf("ordine dei vettori di prova: %f\n",vettore_prova_delta_duration[i]);
		
	}
	
	
	delta_duration_max=vettore_prova_delta_duration[N-1];
	
	delta_duration_min=vettore_prova_delta_duration[0];

	
	printf("delta duration min = %f\tdelta duration max = %f\n\n",delta_duration_min,delta_duration_max);
	
	float delta_duration_norm[i];
	
	if(delta_duration_max==delta_duration_min) {
		for(i=0;i<N;i++) {
			delta_duration_norm[i]=delta_duration[i];
		}
	}
	else {
		delta_duration_norm[0]=(delta_duration[0]-delta_duration_min)/(delta_duration_max-delta_duration_min);
		printf("delta duration min (0) = %f\n\n",delta_duration[0]);  //stampato per controllare il metodo
		
		for(i=0;i<N;i++) {
			delta_duration_norm[i]=(delta_duration[i]-delta_duration_min)/(delta_duration_max-delta_duration_min);
			printf("delta duration %d = %f\n",i, delta_duration_norm[i]);
			
		}
	}
	
	
	printf("\n\nINTENSITA'. Distanze dai valori medi:\n");
	
	for (i=0;i<N;i++) {
		
		//delta_intensity[i]=sqrt((intensity[i]-mean_value_intensity)*(intensity[i]-mean_value_intensity))/((intensity[i]+mean_value_intensity)*(intensity[i]+mean_value_intensity));
		
		delta_intensity[i]=sqrt((intensity[i]-mean_value_intensity)*(intensity[i]-mean_value_intensity));
		
	}
	
	printf("\n\n\n");
		   
	
	
	
	/* NORMALIZZAZIONE INTENSITA' */
	
	float delta_intensity_max, delta_intensity_min;
	
	float vettore_prova_delta_intensity[N];
	
	for(i=0;i<N;i++) {
		
		vettore_prova_delta_intensity[i]=delta_intensity[i];  //così creo un vettore nuovo con i valori di delta intensity, che però conservo
		//nell'ordine giusto
		
	}
	
	
	for(i=0;i<N;i++) {   //attenzione, utilizzo qui "vettore" che però ha valori diversi rispetto a prima
		
		for(j=0;j<N-1;j++) {
			
			if(vettore_prova_delta_intensity[j]>vettore_prova_delta_intensity[j+1]) {
				vettore = vettore_prova_delta_intensity[j];
				vettore_prova_delta_intensity[j]=vettore_prova_delta_intensity[j+1];
				vettore_prova_delta_intensity[j+1]=vettore;
			}
			//ordine crescente
			
		}
		
		
	}
	
	//così l'ultimo vettore, l'N-esimo, sarà il più grande.
	
	
	for(i=0;i<N;i++) {
		
		printf("ordine dei vettori di prova: %f\n",vettore_prova_delta_intensity[i]);
		
	}
	
	
	delta_intensity_max=vettore_prova_delta_intensity[N-1];
	delta_intensity_min=vettore_prova_delta_intensity[0];
	
	
	printf("delta intensity min = %f\tdelta intensity max = %f\n\n",delta_intensity_min,delta_intensity_max);
	
	float delta_intensity_norm[i];
	
	if(delta_intensity_max==delta_intensity_min) {
		delta_intensity_norm[i]=delta_intensity[i];
	}
	
	else {
		
		delta_intensity_norm[0]=(delta_intensity[0]-delta_intensity_min)/(delta_intensity_max-delta_intensity_min);
		printf("delta intensity norm min (0) = %f\n\n",delta_intensity[0]);  //stampato per controllare il metodo
		
		for(i=0;i<N;i++) {
			delta_intensity_norm[i]=(delta_intensity[i]-delta_intensity_min)/(delta_intensity_max-delta_intensity_min);
			printf("delta intensita' normalizzate %d = %f\n",i, delta_intensity_norm[i]);
			
		}
	}
		
	
	
	//Tutti i delta sono compresi fra 0 e 1.
	

	// DEFINISCO I CONTATORI direttamente per gli elementi di matrice.
	
	
	
	
	/* Matrice variazioni frequenze-start */
	
	//contatori relativi ai singoli elementi di matrice
	
	float count_frequency_start_11,count_frequency_start_12,count_frequency_start_13,count_frequency_start_14,
	count_frequency_start_21,count_frequency_start_22,count_frequency_start_23,count_frequency_start_24,
	count_frequency_start_31,count_frequency_start_32,count_frequency_start_33,count_frequency_start_34,
	count_frequency_start_41,count_frequency_start_42,count_frequency_start_43,count_frequency_start_44;
	
	//azzerare i contatori
	
	count_frequency_start_11=0;
	count_frequency_start_12=0;
	count_frequency_start_13=0;
	count_frequency_start_14=0;
	count_frequency_start_21=0;
	count_frequency_start_22=0;
	count_frequency_start_23=0;
	count_frequency_start_24=0;
	count_frequency_start_31=0;
	count_frequency_start_32=0;
	count_frequency_start_33=0;
	count_frequency_start_34=0;
	count_frequency_start_41=0;
	count_frequency_start_42=0;
	count_frequency_start_43=0;
	count_frequency_start_44=0;
	
	
	//poi:
	
	
	//COLONNE: START, RIGHE: FREQUENZE (o al contrario???)
	
	for(i=0;i<N;i++) {
		
		
		//prima riga
		if(delta_frequency_norm[i] <0.25) {
			//prima colonna
			if(delta_start_norm[i]<0.25) count_frequency_start_11++;
			//seconda colonna
			else if (delta_start_norm[i]>=0.25 & delta_start_norm[i]<0.5) count_frequency_start_12++;
			//terza colonna
			else if(delta_start_norm[i]>=0.5 & delta_start_norm[i]<0.75) count_frequency_start_13++;
			//quarta colonna
			else if (delta_start_norm[i]>=0.75) count_frequency_start_14++;
				} 
		
		//seconda riga
		else if(delta_frequency_norm[i] >=0.25 & delta_frequency_norm[i]<0.5) {
			//prima colonna
			if(delta_start_norm[i]<0.25) count_frequency_start_21++;
			//seconda colonna
			else if (delta_start_norm[i]>=0.25 & delta_start_norm[i]<0.5) count_frequency_start_22++;
			//terza colonna
			else if(delta_start_norm[i]>=0.5 & delta_start_norm[i]<0.75) count_frequency_start_23++;
			//quarta colonna
			else if (delta_start_norm[i]>=0.75) count_frequency_start_24++;
		} 
		
		//terza riga
		else if(delta_frequency_norm[i] >=0.5 & delta_frequency_norm[i]<0.75) {
			//prima colonna
			if(delta_start_norm[i]<0.25) count_frequency_start_31++;
			//seconda colonna
			else if (delta_start_norm[i]>=0.25 & delta_start_norm[i]<0.5) count_frequency_start_32++;
			//terza colonna
			else if(delta_start_norm[i]>=0.5 & delta_start_norm[i]<0.75) count_frequency_start_33++;
			//quarta colonna
			else if (delta_start_norm[i]>=0.75) count_frequency_start_34++;
		} 
		
		//quarta riga
		else if(delta_frequency_norm[i] >0.75) {
			//prima colonna
			if(delta_start_norm[i]<0.25) count_frequency_start_41++;
			//seconda colonna
			else if (delta_start_norm[i]>=0.25 & delta_start_norm[i]<0.5) count_frequency_start_42++;
			//terza colonna
			else if(delta_start_norm[i]>=0.5 & delta_start_norm[i]<0.75) count_frequency_start_43++;
			//quarta colonna
			else if (delta_start_norm[i]>=0.75) count_frequency_start_44++;
		} 
	}
		
	
	//matrice vera e propria
	
	float matrix_frequency_start[5][5]; //se comincio a numerare da 1 -> non 4 ma 5.
	
	matrix_frequency_start[1][1]=count_frequency_start_11/N;
	matrix_frequency_start[1][2]=count_frequency_start_12/N;
	matrix_frequency_start[1][3]=count_frequency_start_13/N;
	matrix_frequency_start[1][4]=count_frequency_start_14/N;
	matrix_frequency_start[2][1]=count_frequency_start_21/N;
	matrix_frequency_start[2][2]=count_frequency_start_22/N;
	matrix_frequency_start[2][3]=count_frequency_start_23/N;
	matrix_frequency_start[2][4]=count_frequency_start_24/N;
	matrix_frequency_start[3][1]=count_frequency_start_31/N;
	matrix_frequency_start[3][2]=count_frequency_start_32/N;
	matrix_frequency_start[3][3]=count_frequency_start_33/N;
	matrix_frequency_start[3][4]=count_frequency_start_34/N;
	matrix_frequency_start[4][1]=count_frequency_start_41/N;
	matrix_frequency_start[4][2]=count_frequency_start_42/N;
	matrix_frequency_start[4][3]=count_frequency_start_43/N;
	matrix_frequency_start[4][4]=count_frequency_start_44/N;
	
	
	printf("\n La matrice frequenze-start e' \n\n");
	
	for(i=1;i<5;i++) { //indice di riga
		for(j=1;j<5;j++) {  //indice di colonna
			printf("%.2f\t",matrix_frequency_start[i][j]); //con %.1f stampa float con una sola cifra decimale
		}
		printf("\n");
	}
	printf("\n\n");
	
	
	for(i=1;i<5;i++) { //indice di riga
		for(j=1;j<5;j++) {  //indice di colonna
			fprintf(file_dati_uscita_frequency_start,"%.2f\t",matrix_frequency_start[i][j]); //con %.1f stampa float con una sola cifra decimale
		}
		fprintf(file_dati_uscita_frequency_start,"\n");
	}
	
	
	
	/* Matrice variazioni frequenze-durate */

	
	//contatori relativi ai singoli elementi di matrice
	
	float count_frequency_duration_11,count_frequency_duration_12,count_frequency_duration_13,count_frequency_duration_14,
	count_frequency_duration_21,count_frequency_duration_22,count_frequency_duration_23,count_frequency_duration_24,
	count_frequency_duration_31,count_frequency_duration_32,count_frequency_duration_33,count_frequency_duration_34,
	count_frequency_duration_41,count_frequency_duration_42,count_frequency_duration_43,count_frequency_duration_44;
	
	//azzerare i contatori
	
	count_frequency_duration_11=0;
	count_frequency_duration_12=0;
	count_frequency_duration_13=0;
	count_frequency_duration_14=0;
	count_frequency_duration_21=0;
	count_frequency_duration_22=0;
	count_frequency_duration_23=0;
	count_frequency_duration_24=0;
	count_frequency_duration_31=0;
	count_frequency_duration_32=0;
	count_frequency_duration_33=0;
	count_frequency_duration_34=0;
	count_frequency_duration_41=0;
	count_frequency_duration_42=0;
	count_frequency_duration_43=0;
	count_frequency_duration_44=0;
	
	
	//poi:
	
	
	//COLONNE: DURATE, RIGHE: FREQUENZE (o al contrario???)
	
	for(i=0;i<N;i++) {
		
		
		//prima riga
		if(delta_frequency_norm[i] <0.25) {
			//prima colonna
			if(delta_duration_norm[i]<0.25) count_frequency_duration_11++;
			//seconda colonna
			else if (delta_duration_norm[i]>=0.25 & delta_duration_norm[i]<0.5) count_frequency_duration_12++;
			//terza colonna
			else if(delta_duration_norm[i]>=0.5 & delta_duration_norm[i]<0.75) count_frequency_duration_13++;
			//quarta colonna
			else if (delta_duration_norm[i]>=0.75) count_frequency_duration_14++;
		} 
		
		//seconda riga
		else if(delta_frequency_norm[i] >=0.25 & delta_frequency_norm[i]<0.5) {
			//prima colonna
			if(delta_duration_norm[i]<0.25) count_frequency_start_21++;
			//seconda colonna
			else if (delta_duration_norm[i]>=0.25 & delta_duration_norm[i]<0.5) count_frequency_duration_22++;
			//terza colonna
			else if(delta_duration_norm[i]>=0.5 & delta_duration_norm[i]<0.75) count_frequency_duration_23++;
			//quarta colonna
			else if (delta_duration_norm[i]>=0.75) count_frequency_duration_24++;
		} 
		
		//terza riga
		else if(delta_frequency_norm[i] >=0.5 & delta_frequency_norm[i]<0.75) {
			//prima colonna
			if(delta_duration_norm[i]<0.25) count_frequency_duration_31++;
			//seconda colonna
			else if (delta_duration_norm[i]>=0.25 & delta_duration_norm[i]<0.5) count_frequency_duration_32++;
			//terza colonna
			else if(delta_duration_norm[i]>=0.5 & delta_duration_norm[i]<0.75) count_frequency_duration_33++;
			//quarta colonna
			else if (delta_duration_norm[i]>=0.75) count_frequency_duration_34++;
		} 
		
		//quarta riga
		else if(delta_frequency_norm[i] >0.75) {
			//prima colonna
			if(delta_duration_norm[i]<0.25) count_frequency_duration_41++;
			//seconda colonna
			else if (delta_duration_norm[i]>=0.25 & delta_duration_norm[i]<0.5) count_frequency_duration_42++;
			//terza colonna
			else if(delta_duration_norm[i]>=0.5 & delta_duration_norm[i]<0.75) count_frequency_duration_43++;
			//quarta colonna
			else if (delta_duration_norm[i]>=0.75) count_frequency_duration_44++;
		} 
	}
	
	
	//matrice vera e propria
	
	float matrix_frequency_duration[5][5]; //se comincio a numerare da 1 -> non 4 ma 5.
	
	matrix_frequency_duration[1][1]=count_frequency_duration_11/N;
	matrix_frequency_duration[1][2]=count_frequency_duration_12/N;
	matrix_frequency_duration[1][3]=count_frequency_duration_13/N;
	matrix_frequency_duration[1][4]=count_frequency_duration_14/N;
	matrix_frequency_duration[2][1]=count_frequency_duration_21/N;
	matrix_frequency_duration[2][2]=count_frequency_duration_22/N;
	matrix_frequency_duration[2][3]=count_frequency_duration_23/N;
	matrix_frequency_duration[2][4]=count_frequency_duration_24/N;
	matrix_frequency_duration[3][1]=count_frequency_duration_31/N;
	matrix_frequency_duration[3][2]=count_frequency_duration_32/N;
	matrix_frequency_duration[3][3]=count_frequency_duration_33/N;
	matrix_frequency_duration[3][4]=count_frequency_duration_34/N;
	matrix_frequency_duration[4][1]=count_frequency_duration_41/N;
	matrix_frequency_duration[4][2]=count_frequency_duration_42/N;
	matrix_frequency_duration[4][3]=count_frequency_duration_43/N;
	matrix_frequency_duration[4][4]=count_frequency_duration_44/N;
	
	
	printf("\n La matrice frequenze-durate e' \n\n");
	
	for(i=1;i<5;i++) { //indice di riga
		for(j=1;j<5;j++) {  //indice di colonna
			printf("%.2f\t",matrix_frequency_duration[i][j]); 
		}
		printf("\n");
	}
	printf("\n\n");
	
	
	
	
	for(i=1;i<5;i++) { //indice di riga
		for(j=1;j<5;j++) {  //indice di colonna
			fprintf(file_dati_uscita_frequency_duration,"%.2f\t",matrix_frequency_duration[i][j]); 
		}
		fprintf(file_dati_uscita_frequency_duration,"\n");
	}
	printf("\n\n");
	
	//normalizzo la matrice
	
	
	
	/* Matrice variazioni frequenze-intensità */
	
	
	//contatori relativi ai singoli elementi di matrice
	
	float count_frequency_intensity_11,count_frequency_intensity_12,count_frequency_intensity_13,count_frequency_intensity_14,
	count_frequency_intensity_21,count_frequency_intensity_22,count_frequency_intensity_23,count_frequency_intensity_24,
	count_frequency_intensity_31,count_frequency_intensity_32,count_frequency_intensity_33,count_frequency_intensity_34,
	count_frequency_intensity_41,count_frequency_intensity_42,count_frequency_intensity_43,count_frequency_intensity_44;
	
	//azzerare i contatori
	
	count_frequency_intensity_11=0;
	count_frequency_intensity_12=0;
	count_frequency_intensity_13=0;
	count_frequency_intensity_14=0;
	count_frequency_intensity_21=0;
	count_frequency_intensity_22=0;
	count_frequency_intensity_23=0;
	count_frequency_intensity_24=0;
	count_frequency_intensity_31=0;
	count_frequency_intensity_32=0;
	count_frequency_intensity_33=0;
	count_frequency_intensity_34=0;
	count_frequency_intensity_41=0;
	count_frequency_intensity_42=0;
	count_frequency_intensity_43=0;
	count_frequency_intensity_44=0;
	
	
	//poi:
	
	
	//COLONNE: INTENSITA', RIGHE: FREQUENZE (o al contrario???)
	
	for(i=0;i<N;i++) {
		
		
		//prima riga
		if(delta_frequency_norm[i] <0.25) {
			//prima colonna
			if(delta_intensity_norm[i]<0.25) count_frequency_intensity_11++;
			//seconda colonna
			else if (delta_intensity_norm[i]>=0.25 & delta_intensity_norm[i]<0.5) count_frequency_intensity_12++;
			//terza colonna
			else if(delta_intensity_norm[i]>=0.5 & delta_intensity_norm[i]<0.75) count_frequency_intensity_13++;
			//quarta colonna
			else if (delta_intensity_norm[i]>=0.75) count_frequency_intensity_14++;
		} 
		
		//seconda riga
		else if(delta_frequency_norm[i] >=0.25 & delta_frequency_norm[i]<0.5) {
			//prima colonna
			if(delta_intensity_norm[i]<0.25) count_frequency_intensity_21++;
			//seconda colonna
			else if (delta_intensity_norm[i]>=0.25 & delta_intensity_norm[i]<0.5) count_frequency_intensity_22++;
			//terza colonna
			else if(delta_intensity_norm[i]>=0.5 & delta_intensity_norm[i]<0.75) count_frequency_intensity_23++;
			//quarta colonna
			else if (delta_intensity_norm[i]>=0.75) count_frequency_intensity_24++;
		} 
		
		//terza riga
		else if(delta_frequency_norm[i] >=0.5 & delta_frequency_norm[i]<0.75) {
			//prima colonna
			if(delta_intensity_norm[i]<0.25) count_frequency_intensity_31++;
			//seconda colonna
			else if (delta_intensity_norm[i]>=0.25 & delta_intensity_norm[i]<0.5) count_frequency_intensity_32++;
			//terza colonna
			else if(delta_intensity_norm[i]>=0.5 & delta_intensity_norm[i]<0.75) count_frequency_intensity_33++;
			//quarta colonna
			else if (delta_intensity_norm[i]>=0.75) count_frequency_intensity_34++;
		} 
		
		//quarta riga
		else if(delta_frequency_norm[i] >0.75) {
			//prima colonna
			if(delta_intensity_norm[i]<0.25) count_frequency_intensity_41++;
			//seconda colonna
			else if (delta_intensity_norm[i]>=0.25 & delta_intensity_norm[i]<0.5) count_frequency_intensity_42++;
			//terza colonna
			else if(delta_intensity_norm[i]>=0.5 & delta_intensity_norm[i]<0.75) count_frequency_intensity_43++;
			//quarta colonna
			else if (delta_intensity_norm[i]>=0.75) count_frequency_intensity_44++;
		} 
	}
	
	
	//matrice vera e propria
	
	float matrix_frequency_intensity[5][5]; //se comincio a numerare da 1 -> non 4 ma 5.
	
	matrix_frequency_intensity[1][1]=count_frequency_intensity_11/N;
	matrix_frequency_intensity[1][2]=count_frequency_intensity_12/N;
	matrix_frequency_intensity[1][3]=count_frequency_intensity_13/N;
	matrix_frequency_intensity[1][4]=count_frequency_intensity_14/N;
	matrix_frequency_intensity[2][1]=count_frequency_intensity_21/N;
	matrix_frequency_intensity[2][2]=count_frequency_intensity_22/N;
	matrix_frequency_intensity[2][3]=count_frequency_intensity_23/N;
	matrix_frequency_intensity[2][4]=count_frequency_intensity_24/N;
	matrix_frequency_intensity[3][1]=count_frequency_intensity_31/N;
	matrix_frequency_intensity[3][2]=count_frequency_intensity_32/N;
	matrix_frequency_intensity[3][3]=count_frequency_intensity_33/N;
	matrix_frequency_intensity[3][4]=count_frequency_intensity_34/N;
	matrix_frequency_intensity[4][1]=count_frequency_intensity_41/N;
	matrix_frequency_intensity[4][2]=count_frequency_intensity_42/N;
	matrix_frequency_intensity[4][3]=count_frequency_intensity_43/N;
	matrix_frequency_intensity[4][4]=count_frequency_intensity_44/N;
	
	
	printf("\n La matrice frequenze-intensità e' \n\n");
	
	for(i=1;i<5;i++) { //indice di riga
		for(j=1;j<5;j++) {  //indice di colonna
			printf("%.2f\t",matrix_frequency_intensity[i][j]); //con %.1f stampa float con una sola cifra decimale
		}
		printf("\n");
	}
	printf("\n\n");
	
	
	for(i=1;i<5;i++) { //indice di riga
		for(j=1;j<5;j++) {  //indice di colonna
			fprintf(file_dati_uscita_frequency_intensity,"%.2f\t",matrix_frequency_intensity[i][j]); //con %.1f stampa float con una sola cifra decimale
		}
		fprintf(file_dati_uscita_frequency_intensity,"\n");
	}
	printf("\n\n");
	
	//normalizzo la matrice
	
	
	
	
	/* Matrice variazioni start-intensità */
	
	
	//contatori relativi ai singoli elementi di matrice
	
	float count_duration_intensity_11,count_duration_intensity_12,count_duration_intensity_13,count_duration_intensity_14,
	count_duration_intensity_21,count_duration_intensity_22,count_duration_intensity_23,count_duration_intensity_24,
	count_duration_intensity_31,count_duration_intensity_32,count_duration_intensity_33,count_duration_intensity_34,
	count_duration_intensity_41,count_duration_intensity_42,count_duration_intensity_43,count_duration_intensity_44;
	
	//azzerare i contatori
	
	count_duration_intensity_11=0;
	count_duration_intensity_12=0;
	count_duration_intensity_13=0;
	count_duration_intensity_14=0;
	count_duration_intensity_21=0;
	count_duration_intensity_22=0;
	count_duration_intensity_23=0;
	count_duration_intensity_24=0;
	count_duration_intensity_31=0;
	count_duration_intensity_32=0;
	count_duration_intensity_33=0;
	count_duration_intensity_34=0;
	count_duration_intensity_41=0;
	count_duration_intensity_42=0;
	count_duration_intensity_43=0;
	count_duration_intensity_44=0;
	
	
	//poi:
	
	
	//COLONNE: DURATE, RIGHE: INTENSITA' (o al contrario???)
	
	for(i=0;i<N;i++) {
		
		
		//prima riga
		if(delta_duration_norm[i] <0.25) {
			//prima colonna
			if(delta_intensity_norm[i]<0.25) count_duration_intensity_11++;
			//seconda colonna
			else if (delta_intensity_norm[i]>=0.25 & delta_intensity_norm[i]<0.5) count_duration_intensity_12++;
			//terza colonna
			else if(delta_intensity_norm[i]>=0.5 & delta_intensity_norm[i]<0.75) count_duration_intensity_13++;
			//quarta colonna
			else if (delta_intensity_norm[i]>=0.75) count_duration_intensity_14++;
		} 
		
		//seconda riga
		else if(delta_duration_norm[i] >=0.25 & delta_duration_norm[i]<0.5) {
			//prima colonna
			if(delta_intensity_norm[i]<0.25) count_duration_intensity_21++;
			//seconda colonna
			else if (delta_intensity_norm[i]>=0.25 & delta_intensity_norm[i]<0.5) count_duration_intensity_22++;
			//terza colonna
			else if(delta_intensity_norm[i]>=0.5 & delta_intensity_norm[i]<0.75) count_duration_intensity_23++;
			//quarta colonna
			else if (delta_intensity_norm[i]>=0.75) count_duration_intensity_24++;
		} 
		
		//terza riga
		else if(delta_duration_norm[i] >=0.5 & delta_duration_norm[i]<0.75) {
			//prima colonna
			if(delta_intensity_norm[i]<0.25) count_duration_intensity_31++;
			//seconda colonna
			else if (delta_intensity_norm[i]>=0.25 & delta_intensity_norm[i]<0.5) count_duration_intensity_32++;
			//terza colonna
			else if(delta_intensity_norm[i]>=0.5 & delta_intensity_norm[i]<0.75) count_duration_intensity_33++;
			//quarta colonna
			else if (delta_intensity_norm[i]>=0.75) count_duration_intensity_34++;
		} 
		
		//quarta riga
		else if(delta_duration_norm[i] >0.75) {
			//prima colonna
			if(delta_intensity_norm[i]<0.25) count_duration_intensity_41++;
			//seconda colonna
			else if (delta_intensity_norm[i]>=0.25 & delta_intensity_norm[i]<0.5) count_duration_intensity_42++;
			//terza colonna
			else if(delta_intensity_norm[i]>=0.5 & delta_intensity_norm[i]<0.75) count_duration_intensity_43++;
			//quarta colonna
			else if (delta_intensity_norm[i]>=0.75) count_duration_intensity_44++;
		} 
	}
	
	
	//matrice vera e propria
	
	float matrix_duration_intensity[5][5]; //se comincio a numerare da 1 -> non 4 ma 5.
	
	matrix_duration_intensity[1][1]=count_duration_intensity_11/N;
	matrix_duration_intensity[1][2]=count_duration_intensity_12/N;
	matrix_duration_intensity[1][3]=count_duration_intensity_13/N;
	matrix_duration_intensity[1][4]=count_duration_intensity_14/N;
	matrix_duration_intensity[2][1]=count_duration_intensity_21/N;
	matrix_duration_intensity[2][2]=count_duration_intensity_22/N;
	matrix_duration_intensity[2][3]=count_duration_intensity_23/N;
	matrix_duration_intensity[2][4]=count_duration_intensity_24/N;
	matrix_duration_intensity[3][1]=count_duration_intensity_31/N;
	matrix_duration_intensity[3][2]=count_duration_intensity_32/N;
	matrix_duration_intensity[3][3]=count_duration_intensity_33/N;
	matrix_duration_intensity[3][4]=count_duration_intensity_34/N;
	matrix_duration_intensity[4][1]=count_duration_intensity_41/N;
	matrix_duration_intensity[4][2]=count_duration_intensity_42/N;
	matrix_duration_intensity[4][3]=count_duration_intensity_43/N;
	matrix_duration_intensity[4][4]=count_duration_intensity_44/N;
	
	
	printf("\n La matrice durate-intensità e' \n\n");
	
	for(i=1;i<5;i++) { //indice di riga
		for(j=1;j<5;j++) {  //indice di colonna
			printf("%.2f\t",matrix_duration_intensity[i][j]); //con %.1f stampa float con una sola cifra decimale
		}
		printf("\n");
	}
	printf("\n\n");
	
	
	for(i=1;i<5;i++) { //indice di riga
		for(j=1;j<5;j++) {  //indice di colonna
			fprintf(file_dati_uscita_duration_intensity,"%.2f\t",matrix_duration_intensity[i][j]); //con %.1f stampa float con una sola cifra decimale
		}
		fprintf(file_dati_uscita_duration_intensity,"\n");
	}
	printf("\n\n");
	
	
	
	/* Matrice variazioni start-intensità */
	
	
	//contatori relativi ai singoli elementi di matrice
	
	float count_start_intensity_11,count_start_intensity_12,count_start_intensity_13,count_start_intensity_14,
	count_start_intensity_21,count_start_intensity_22,count_start_intensity_23,count_start_intensity_24,
	count_start_intensity_31,count_start_intensity_32,count_start_intensity_33,count_start_intensity_34,
	count_start_intensity_41,count_start_intensity_42,count_start_intensity_43,count_start_intensity_44;
	
	//azzerare i contatori
	
	count_start_intensity_11=0;
	count_start_intensity_12=0;
	count_start_intensity_13=0;
	count_start_intensity_14=0;
	count_start_intensity_21=0;
	count_start_intensity_22=0;
	count_start_intensity_23=0;
	count_start_intensity_24=0;
	count_start_intensity_31=0;
	count_start_intensity_32=0;
	count_start_intensity_33=0;
	count_start_intensity_34=0;
	count_start_intensity_41=0;
	count_start_intensity_42=0;
	count_start_intensity_43=0;
	count_start_intensity_44=0;
	
	
	//poi:
	
	
	//COLONNE: START, RIGHE: INTENSITA' (o al contrario???)
	
	for(i=0;i<N;i++) {
		
		
		//prima riga
		if(delta_start_norm[i] <0.25) {
			//prima colonna
			if(delta_intensity_norm[i]<0.25) count_start_intensity_11++;
			//seconda colonna
			else if (delta_intensity_norm[i]>=0.25 & delta_intensity_norm[i]<0.5) count_start_intensity_12++;
			//terza colonna
			else if(delta_intensity_norm[i]>=0.5 & delta_intensity_norm[i]<0.75) count_start_intensity_13++;
			//quarta colonna
			else if (delta_intensity_norm[i]>=0.75) count_start_intensity_14++;
		} 
		
		//seconda riga
		else if(delta_start_norm[i] >=0.25 & delta_start_norm[i]<0.5) {
			//prima colonna
			if(delta_intensity_norm[i]<0.25) count_start_intensity_21++;
			//seconda colonna
			else if (delta_intensity_norm[i]>=0.25 & delta_intensity_norm[i]<0.5) count_start_intensity_22++;
			//terza colonna
			else if(delta_intensity_norm[i]>=0.5 & delta_intensity_norm[i]<0.75) count_start_intensity_23++;
			//quarta colonna
			else if (delta_intensity_norm[i]>=0.75) count_start_intensity_24++;
		} 
		
		//terza riga
		else if(delta_start_norm[i] >=0.5 & delta_start_norm[i]<0.75) {
			//prima colonna
			if(delta_intensity_norm[i]<0.25) count_start_intensity_31++;
			//seconda colonna
			else if (delta_intensity_norm[i]>=0.25 & delta_intensity_norm[i]<0.5) count_start_intensity_32++;
			//terza colonna
			else if(delta_intensity_norm[i]>=0.5 & delta_intensity_norm[i]<0.75) count_start_intensity_33++;
			//quarta colonna
			else if (delta_intensity_norm[i]>=0.75) count_start_intensity_34++;
		} 
		
		//quarta riga
		else if(delta_duration_norm[i] >0.75) {
			//prima colonna
			if(delta_intensity_norm[i]<0.25) count_start_intensity_41++;
			//seconda colonna
			else if (delta_intensity_norm[i]>=0.25 & delta_intensity_norm[i]<0.5) count_start_intensity_42++;
			//terza colonna
			else if(delta_intensity_norm[i]>=0.5 & delta_intensity_norm[i]<0.75) count_start_intensity_43++;
			//quarta colonna
			else if (delta_intensity_norm[i]>=0.75) count_start_intensity_44++;
		} 
	}
	
	
	//matrice vera e propria
	
	float matrix_start_intensity[5][5]; //se comincio a numerare da 1 -> non 4 ma 5.
	
	matrix_start_intensity[1][1]=count_start_intensity_11/N;
	matrix_start_intensity[1][2]=count_start_intensity_12/N;
	matrix_start_intensity[1][3]=count_start_intensity_13/N;
	matrix_start_intensity[1][4]=count_start_intensity_14/N;
	matrix_start_intensity[2][1]=count_start_intensity_21/N;
	matrix_start_intensity[2][2]=count_start_intensity_22/N;
	matrix_start_intensity[2][3]=count_start_intensity_23/N;
	matrix_start_intensity[2][4]=count_start_intensity_24/N;
	matrix_start_intensity[3][1]=count_start_intensity_31/N;
	matrix_start_intensity[3][2]=count_start_intensity_32/N;
	matrix_start_intensity[3][3]=count_start_intensity_33/N;
	matrix_start_intensity[3][4]=count_start_intensity_34/N;
	matrix_start_intensity[4][1]=count_start_intensity_41/N;
	matrix_start_intensity[4][2]=count_start_intensity_42/N;
	matrix_start_intensity[4][3]=count_start_intensity_43/N;
	matrix_start_intensity[4][4]=count_start_intensity_44/N;
	
	
	printf("\n La matrice start-intensità e' \n\n");
	
	for(i=1;i<5;i++) { //indice di riga
		for(j=1;j<5;j++) {  //indice di colonna
			printf("%.2f\t",matrix_start_intensity[i][j]); //con %.1f stampa float con una sola cifra decimale
		}
		printf("\n");
	}
	printf("\n\n");
	
	
	for(i=1;i<5;i++) { //indice di riga
		for(j=1;j<5;j++) {  //indice di colonna
			fprintf(file_dati_uscita_start_intensity,"%.2f\t",matrix_start_intensity[i][j]); //con %.1f stampa float con una sola cifra decimale
		}
		fprintf(file_dati_uscita_start_intensity,"\n");
	}
	printf("\n\n");
	
	
	
	/* Matrice variazioni durate-intensità */
	
}

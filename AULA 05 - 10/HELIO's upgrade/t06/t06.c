#include <stdio.h>
#include <stdlib.h>

int str_tamanho(char*s){
	int i=0;
	while(s[i]!='\0'){
		i++;
	}
	return i;
}

void str_copia(char *s,char *d){
	for (int i = 0; i <= str_tamanho(s); i++)
		d[i]=s[i];
}

char *str_concatena(char *s, char *d){
	int a=str_tamanho(s); 
	int b=str_tamanho(d);
	char *v=(char*)malloc((a+b+1)*sizeof(char));
	if(v==NULL){
		printf("memoria insuficiente");
		return (char*)1;
	}
	for(int i=0;i<a;i++)
		v[i]=s[i];
	for(int i=0;i<=b;i++)
		v[(a+i)]=d[i];
   	return v;
}
char *str_concatenaE(char *s, char *d){
	int a=str_tamanho(s);
	int b=str_tamanho(d); 
	char *v=(char*)malloc((a+b+4)*sizeof(char));
	if(v==NULL){
		printf("memoria insuficiente");
		return (char*)1;
	}
	for(int i=0;i<a;i++)
		v[i]=s[i];
	v[a]=' ';
	v[a+1]='e';
	v[a+2]=' ';
	for(int i=0;i<=b;i++)
		v[(a+i+3)]=d[i];

   	return v;
}

char *saida(char *entrada,int tamanho){

	char*saida="";
	char*centena="";
	char*dezena="";
	char*unidade="";

	if (tamanho-1>=0){
	switch(entrada[tamanho-1]){
		case '0':
			unidade="";
			break;
		case '1':
			unidade="um";
			break;
		case '2':
			unidade="dois";
			break;
		case '3':
			unidade="tres";
			break;
		case '4':
			unidade="quatro";
			break;
		case '5':
			unidade="cinco";
			break;
		case '6':
			unidade="seis";
			break;
		case '7':
			unidade="sete";
			break;
		case '8':
			unidade="oito";
			break;
		case '9':
			unidade="nove";
			break;
	}
	}
	if (tamanho-2>=0){
	switch(entrada[tamanho-2]){
		case '0':
			dezena="";
			break;
		case '1':
			unidade="";
			switch(entrada[tamanho-1]){
				case '0':
					dezena="dez";
					break;
				case '1':
					dezena="onze";
					break;
				case '2':
					dezena="doze";
					break;
				case '3':
					dezena="treze";
					break;
				case '4':
					dezena="quatorze";
					break;
				case '5':
					dezena="quinze";
					break;
				case '6':
					dezena="dezesseis";
					break;
				case '7':
					dezena="dezessete";
					break;
				case '8':
					dezena="dezoito";
					break;
				case '9':
					dezena="dezenove";
					break;
			}
			break;
		case '2':
			dezena="vinte";
			break;
		case '3':
			dezena="trinta";
			break;
		case '4':
			dezena="quarenta";
			break;
		case '5':
			dezena="cinquenta";
			break;
		case '6':
			dezena="sessenta";
			break;
		case '7':
			dezena="setenta";
			break;
		case '8':
			dezena="oitenta";
			break;
		case '9':
			dezena="noventa";
			break;
	}
	}
	if(tamanho-3>=0){
	switch(entrada[tamanho-3]){
		case '1':
			centena="cento";
			break;
		case '2':
			centena="duzentos";
			break;
		case '3':
			centena="trezentos";
			break;
		case '4':
			centena="quatrocentos";
			break;
		case '5':
			centena="quinhentos";
			break;
		case '6':
			centena="seiscentos";
			break;
		case '7':
			centena="setecentos";
			break;
		case '8':
			centena="oitocentos";
			break;
		case '9':
			centena="novecentos";
			break;
	}
	}

	if(str_tamanho(unidade)==0 || str_tamanho(dezena)==0) saida=str_concatena(dezena,unidade);
	else saida=str_concatenaE(dezena,unidade);

	if(str_tamanho(centena)==0 || str_tamanho(saida)==0) saida=str_concatena(centena,saida);
	else saida=str_concatenaE(centena,saida);

	//free(unidade);
	//free(centena);
	//free(dezena);

	char *cento="cento";
	

	for(int i=0;i<=5;i++){
		if(saida[i]!=cento[i]){
			//free(cento);
			return saida;
		}
	}

	//free(cento);
	saida="cem";
	return saida;
}

int main(int narg, char *argv[]){

	if (narg==1){
		char *entrada=(char*)malloc(3*sizeof(char));
		if(entrada==NULL){
			printf("memoria insuficiente");
			return 1;
		}
		printf("insira um numero: ");
		scanf("%s",entrada);
		char *sai=saida(entrada,str_tamanho(entrada));
		printf("%s.\n", sai);
		return 0;
	}

	int i=0;
	int j=0;
	char c;
	char *extenso;

	FILE *arq;
	arq=fopen(argv[1], "rt");
	if(arq==NULL){
		printf("nao foi possivel abrir o arquivo");
		return 1;
	}

	char *numero=(char*)malloc(4*sizeof(char*));
	if(numero==NULL){
		printf("memoria insuficiente1");
		return 1;
	}

	char **vetornumext=(char**)malloc(1000*sizeof(char*));
	if(vetornumext==NULL){
		printf("memoria insuficiente2");
		return 1;
	}

	while((c=fgetc(arq)) != EOF){
		if ( c == '\n'){
			numero[j]='\0';
			extenso=saida(numero,str_tamanho(numero));
			vetornumext[i]=(char*)malloc(str_tamanho(extenso)*sizeof(char));
			if(vetornumext[i]==NULL){
				printf("memoria insuficiente3");
				return 1;
			}
			str_copia(extenso,vetornumext[i]);
			//printf("%s.\n",vetornumext[i]);
			i++;
			j=0;
		}else{
			numero[j]=c;
			j++;
		}
	}
	for (int k = 0; k < i; k++)
		printf("%s.\n", vetornumext[k] );
	fclose(arq);
	return 0;
}

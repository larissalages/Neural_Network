#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class Sample
{
	private:
		double A_TOTAL_AMT_DELQ_1;
		double A_TOTAL_BALANCES;
		double A_TOTAL_NBR_ACCTS;
		double MARITAL_STATUS_1;
		double MARITAL_STATUS_2;
		double MARITAL_STATUS_3;
		double MARITAL_STATUS_4;
		double RENT_BUY_CODE_1;
		double RENT_BUY_CODE_2;
		double RENT_BUY_CODE_3;
		double RENT_BUY_CODE_4;
		double CURR_RES_MTHS;
		double PREV_RES_MTHS;
		double OCCN_CODE;
		double CURR_EMPL_MTHS;
		double PREV_EMPL_MTHS;
		double CHQ_ACCT_IND_1;
		double CHQ_ACCT_IND_2;
		double CHQ_ACCT_IND_3;
		double SAV_ACCT_IND_1;
		double SAV_ACCT_IND_2;
		double SAV_ACCT_IND_3;
		double TOTAL_NBR_CREDIT_CARDS;
		double NBR_OF_DEPENDANTS;
		double AMEX_CARD_1;
		double DINERS_CARD_1;
		double VISA_CARD_1;
		double MASTERCARD_1;
		double RETAIL_CARDS_1;
		double B_ENQ_LAST_WEEK;
		double B_ENQ_L1M;
		double B_ENQ_L3M;
		double B_ENQ_L6M_GR1;
		double B_ENQ_L6M_GR2;
		double B_ENQ_L6M_GR3;
		double B_ENQ_L12M_GR1;
		double B_ENQ_L12M_GR2;
		double B_ENQ_L12M_GR3;
		double B_DEF_PAID_L12M;
		double B_ENQ_L6M;
		double B_DEF_PAID_IND_1;
		double B_DEF_UNPD_IND_1;
		double A_DISTRICT_APPLICANT;
		double DVR_LIC;
		double CREDIT_CARD_TYPE_1;
		double AGE_AT_APPLICATION;
		double TARGET_FLAG_1;
		double TARGET_FLAG_2;

	public:
		Sample() { }
		~Sample() { }
		bool isFromClass1();
		bool ReadSampleFromFile(FILE* f);
		void WriteSampleToFile(FILE* f);
};

bool Sample::isFromClass1()
{ 
	if(TARGET_FLAG_1 == 0 && TARGET_FLAG_2 == 1)
		return true;
	else
		return false;
}

bool Sample::ReadSampleFromFile(FILE* f)
{
	if( 
	fscanf(f, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", 
	&A_TOTAL_AMT_DELQ_1, &A_TOTAL_BALANCES, &A_TOTAL_NBR_ACCTS, &MARITAL_STATUS_1, &MARITAL_STATUS_2, &MARITAL_STATUS_3, &MARITAL_STATUS_4, &RENT_BUY_CODE_1,
 	&RENT_BUY_CODE_2, &RENT_BUY_CODE_3, &RENT_BUY_CODE_4, &CURR_RES_MTHS, &PREV_RES_MTHS, &OCCN_CODE, &CURR_EMPL_MTHS, &PREV_EMPL_MTHS, &CHQ_ACCT_IND_1, &CHQ_ACCT_IND_2, 
	&CHQ_ACCT_IND_3, &SAV_ACCT_IND_1, &SAV_ACCT_IND_2, &SAV_ACCT_IND_3, &TOTAL_NBR_CREDIT_CARDS, &NBR_OF_DEPENDANTS, &AMEX_CARD_1, &DINERS_CARD_1, &VISA_CARD_1, 
	&MASTERCARD_1, &RETAIL_CARDS_1,	&B_ENQ_LAST_WEEK, &B_ENQ_L1M, &B_ENQ_L3M, &B_ENQ_L6M_GR1, &B_ENQ_L6M_GR2, &B_ENQ_L6M_GR3, &B_ENQ_L12M_GR1, &B_ENQ_L12M_GR2, &B_ENQ_L12M_GR3, 
 	&B_DEF_PAID_L12M, &B_ENQ_L6M, &B_DEF_PAID_IND_1, &B_DEF_UNPD_IND_1, &A_DISTRICT_APPLICANT, &DVR_LIC, &CREDIT_CARD_TYPE_1, &AGE_AT_APPLICATION, &TARGET_FLAG_1, &TARGET_FLAG_2) <= 0
	)
		return false;
	else
		return true;
}

void Sample::WriteSampleToFile(FILE* f)
{
	fprintf(f, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n", 
	A_TOTAL_AMT_DELQ_1, A_TOTAL_BALANCES, A_TOTAL_NBR_ACCTS, MARITAL_STATUS_1, MARITAL_STATUS_2, MARITAL_STATUS_3, MARITAL_STATUS_4, RENT_BUY_CODE_1,
 	RENT_BUY_CODE_2, RENT_BUY_CODE_3, RENT_BUY_CODE_4, CURR_RES_MTHS, PREV_RES_MTHS, OCCN_CODE, CURR_EMPL_MTHS, PREV_EMPL_MTHS, CHQ_ACCT_IND_1, CHQ_ACCT_IND_2, 
	CHQ_ACCT_IND_3, SAV_ACCT_IND_1, SAV_ACCT_IND_2, SAV_ACCT_IND_3, TOTAL_NBR_CREDIT_CARDS, NBR_OF_DEPENDANTS, AMEX_CARD_1, DINERS_CARD_1, VISA_CARD_1, 
	MASTERCARD_1, RETAIL_CARDS_1,	B_ENQ_LAST_WEEK, B_ENQ_L1M, B_ENQ_L3M, B_ENQ_L6M_GR1, B_ENQ_L6M_GR2, B_ENQ_L6M_GR3, B_ENQ_L12M_GR1, B_ENQ_L12M_GR2, B_ENQ_L12M_GR3, 
 	B_DEF_PAID_L12M, B_ENQ_L6M, B_DEF_PAID_IND_1, B_DEF_UNPD_IND_1, A_DISTRICT_APPLICANT, DVR_LIC, CREDIT_CARD_TYPE_1, AGE_AT_APPLICATION, TARGET_FLAG_1, TARGET_FLAG_2);
}

void separate_classes()
{
	FILE *f_original = fopen("original.txt", "r");
	FILE *f_class1 = fopen("class1.txt", "w");
	FILE *f_class2 = fopen("class2.txt", "w");
	vector<Sample> vClass1, vClass2;
	Sample s; 

	//Lê cada exemplo do arquivo e coloca no vetor da classe 1 ou da classe 2
	while(s.ReadSampleFromFile(f_original))
	{
		if(s.isFromClass1())
			vClass1.push_back(s);
		else
			vClass2.push_back(s);
	}

	//Escreve o arquivo de exemplos da classe 1 aleatoriamente
	while(vClass1.size() > 0)
	{
       	int indice = rand()%vClass1.size();
		vClass1[indice].WriteSampleToFile(f_class1);
       	vClass1.erase(vClass1.begin()+indice);
	}

	//Escreve o arquivo de exemplos da classe 2 aleatoriamente
	while(vClass2.size() > 0)
	{
       	int indice = rand()%vClass2.size();
		vClass2[indice].WriteSampleToFile(f_class2);
       	vClass2.erase(vClass2.begin()+indice);
	}


	fclose(f_original);
	fclose(f_class1);
	fclose(f_class2);
}

void separate_sets()
{
	FILE *f_class1, *f_class1_treino, *f_class1_validacao, *f_class1_teste;
	FILE *f_class2, *f_class2_treino, *f_class2_validacao, *f_class2_teste;
	vector<Sample> vClass1, vClass2;
	Sample s;

	f_class1 = fopen("class1.txt", "r");
	f_class1_treino = fopen("class1_treino.txt", "w");
	f_class1_validacao = fopen("class1_validacao.txt", "w");
	f_class1_teste = fopen("class1_teste.txt", "w");

	f_class2 = fopen("class2.txt", "r");
	f_class2_treino = fopen("class2_treino.txt", "w");
	f_class2_validacao = fopen("class2_validacao.txt", "w");
	f_class2_teste = fopen("class2_teste.txt", "w");

	//Lê os exemplos dos arquivos de classe
	while(s.ReadSampleFromFile(f_class1))
		vClass1.push_back(s);
	while(s.ReadSampleFromFile(f_class2))
		vClass2.push_back(s);

	//Separa a classe 1 em 3 arquivos (treino, validação e teste)
	for(int i = 0; i < vClass1.size()/2; i++)
		vClass1[i].WriteSampleToFile(f_class1_treino);
	for(int i = vClass1.size()/2; i < (vClass1.size()/2 + vClass1.size()/4); i++)
		vClass1[i].WriteSampleToFile(f_class1_validacao);
	for(int i = (vClass1.size()/2 + vClass1.size()/4); i < vClass1.size(); i++)
		vClass1[i].WriteSampleToFile(f_class1_teste);

	//Separa a classe 2 em 3 arquivos (treino, validação e teste)
	for(int i = 0; i < vClass2.size()/2; i++)
		vClass2[i].WriteSampleToFile(f_class2_treino);
	for(int i = vClass2.size()/2; i < (vClass2.size()/2 + vClass2.size()/4); i++)
		vClass2[i].WriteSampleToFile(f_class2_validacao);
	for(int i = (vClass2.size()/2 + vClass2.size()/4); i < vClass2.size(); i++)
		vClass2[i].WriteSampleToFile(f_class2_teste);

	fclose(f_class1);
	fclose(f_class1_treino);
	fclose(f_class1_validacao);
	fclose(f_class1_teste);
	fclose(f_class2);
	fclose(f_class2_treino);
	fclose(f_class2_validacao);
	fclose(f_class2_teste);
}

void reduce_and_replicate()
{
	FILE *f_class1_treino, *f_class2_treino;
	FILE *f_class1_validacao, *f_class2_validacao;
	FILE *f_class1_treino_reduzido, *f_class2_treino_replicado;
	FILE *f_class1_validacao_reduzido, *f_class2_validacao_replicado;
	vector<Sample> vClass1, vClass2, vClass1_reduzido, vClass2_replicado;
	int size1, size2;
	Sample s;

	f_class1_treino = fopen("class1_treino.txt", "r");
	f_class2_treino = fopen("class2_treino.txt", "r");
	f_class1_validacao = fopen("class1_validacao.txt", "r");
	f_class2_validacao = fopen("class2_validacao.txt", "r");
	f_class1_treino_reduzido = fopen("class1_treino_reduzido.txt", "w");
	f_class2_treino_replicado = fopen("class2_treino_replicado.txt", "w");
	f_class1_validacao_reduzido = fopen("class1_validacao_reduzido.txt", "w");
	f_class2_validacao_replicado = fopen("class2_validacao_replicado.txt", "w");

	//---------------------------------------------------------------------

	//Adiciona os exemplos de treino da classe 1 no vetor 1
	while(s.ReadSampleFromFile(f_class1_treino))
		vClass1.push_back(s);
	size1 = vClass1.size();
	
	//Adiciona os exemplos de treino da classe 2 no vetor 2
	while(s.ReadSampleFromFile(f_class2_treino))
		vClass2.push_back(s);
	size2 = vClass2.size();
	
	//reduz o conjunto de treino da classe 1
	while(vClass1_reduzido.size() < size2)
	{
	  	int indice = rand()%vClass1.size();
       	vClass1_reduzido.push_back(vClass1[indice]);
       	vClass1.erase(vClass1.begin()+indice);
	}

	//replica o conjunto de treino da classe 2
	int i = 0;
	while(vClass2_replicado.size() < size1)
	{
		vClass2_replicado.push_back(vClass2[i]);
		
		i++;
		if(i >= vClass2.size())
			i = 0;
	}

	//Escreve o novo arquivo de treino reduzido da classe 1
	for(i = 0; i < vClass1_reduzido.size(); i++)
		vClass1_reduzido[i].WriteSampleToFile(f_class1_treino_reduzido);

	//Escreve o novo arquivo de treino replicado da classe 2
	for(i = 0; i < vClass2_replicado.size(); i++)
		vClass2_replicado[i].WriteSampleToFile(f_class2_treino_replicado);

	//---------------------------------------------------------------------

	vClass1.clear();
	vClass2.clear();
	vClass1_reduzido.clear();
	vClass2_replicado.clear();

	//Adiciona os exemplos de validação da classe 1 no vetor 1
	while(s.ReadSampleFromFile(f_class1_validacao))
		vClass1.push_back(s);
	size1 = vClass1.size();
	
	//Adiciona os exemplos de validação da classe 2 no vetor 2
	while(s.ReadSampleFromFile(f_class2_validacao))
		vClass2.push_back(s);
	size2 = vClass2.size();
	
	//reduz o conjunto de validação da classe 1
	while(vClass1_reduzido.size() < size2)
	{
	  	int indice = rand()%vClass1.size();
       	vClass1_reduzido.push_back(vClass1[indice]);
       	vClass1.erase(vClass1.begin()+indice);
	}

	//replica o conjunto de validação da classe 2
	i = 0;
	while(vClass2_replicado.size() < size1)
	{
		vClass2_replicado.push_back(vClass2[i]);
		
		i++;
		if(i >= vClass2.size())
			i = 0;
	}

	//Escreve o novo arquivo de validação reduzido da classe 1
	for(i = 0; i < vClass1_reduzido.size(); i++)
		vClass1_reduzido[i].WriteSampleToFile(f_class1_validacao_reduzido);

	//Escreve o novo arquivo de validação replicado da classe 2
	for(i = 0; i < vClass2_replicado.size(); i++)
		vClass2_replicado[i].WriteSampleToFile(f_class2_validacao_replicado);
	
	//---------------------------------------------------------------------

	fclose(f_class1_treino);
	fclose(f_class2_treino);
	fclose(f_class1_validacao);
	fclose(f_class2_validacao);
	fclose(f_class1_treino_reduzido);
	fclose(f_class2_treino_replicado);
	fclose(f_class1_validacao_reduzido);
	fclose(f_class2_validacao_replicado);
}

void merge(int type)
{    
	FILE *f_class1, *f_class2, *f_merge;
	vector<Sample> vClass1, vClass2, vMerge;
	Sample s;

	//Abre arquivos dependendo dos conjuntos que quer juntar que é controlado
	//pelo parametro type
	if(type == 0) //Undersampling random
	{
		f_class1 = fopen("class1_treino_reduzido.txt", "r");
		f_class2 = fopen("class2_treino.txt", "r");
		f_merge = fopen("treino_undersampling.txt", "w");
	}
	
	else if(type == 1) //oversampling replicado
	{
		f_class1 = fopen("class1_treino.txt", "r");
		f_class2 = fopen("class2_treino_replicado.txt", "r");
		f_merge = fopen("treino_oversampling.txt", "w");
	}

	else if(type == 2) //validacao random
	{
		f_class1 = fopen("class1_validacao_reduzido.txt", "r");
		f_class2 = fopen("class2_validacao.txt", "r");
		f_merge = fopen("validacao_undersampling.txt", "w");
	}
	
	else if(type == 3) //validcao replicado
	{
		f_class1 = fopen("class1_validacao.txt", "r");
		f_class2 = fopen("class2_validacao_replicado.txt", "r");
		f_merge = fopen("validacao_oversampling.txt", "w");
	}

	else if(type == 4)
	{
		f_class1 = fopen("class1_teste.txt", "r");
		f_class2 = fopen("class2_teste.txt", "r");
		f_merge = fopen("teste.txt", "w");
	}
	else if(type == 5) //k means Treino
	{
		f_class1 = fopen("class1_treino_kmeans.txt", "r");
		f_class2 = fopen("class2_treino.txt", "r");
		f_merge = fopen("treino_undersamplingKM.txt", "w");
	}
	else if(type == 6) //SMOTE Treino
	{
		f_class1 = fopen("class1_treino.txt", "r");
		f_class2 = fopen("class2_treino_oversampling_SMOTE.txt", "r");
		f_merge = fopen("treino_oversamplingSMT.txt", "w");
	}
	else if(type == 7) //SMOTE adaptado Treino
	{
		f_class1 = fopen("class1_treino.txt", "r");
		f_class2 = fopen("class2_treino_oversampling_SMOTEadaptado.txt", "r");
		f_merge = fopen("treino_oversamplingSMTadp.txt", "w");
	}
	else if(type == 8) //k means Validacao
	{
		f_class1 = fopen("class1_validacao_kmeans.txt", "r");
		f_class2 = fopen("class2_validacao.txt", "r");
		f_merge = fopen("validacao_undersamplingKM.txt", "w");
	}
	else if(type == 9) //SMOTE Validacao
	{
		f_class1 = fopen("class1_validacao.txt", "r");
		f_class2 = fopen("class2_validacao_oversampling_SMOTE.txt", "r");
		f_merge = fopen("validacao_oversamplingSMT.txt", "w");

	}
	else if(type == 10) //SMOTE adaptado Validacao
	{
		f_class1 = fopen("class1_validacao.txt", "r");
		f_class2 = fopen("class2_validacao_oversampling_SMOTE_adaptado.txt", "r");
		f_merge = fopen("validacao_oversamplingSMTadp.txt", "w");
	}

	
    //Lê amostras da classe 1 e 2 e coloca nos vetores
	while(s.ReadSampleFromFile(f_class1))
		vClass1.push_back(s);

	while(s.ReadSampleFromFile(f_class2))
		vClass2.push_back(s);

    //Gera vetor conjunto a partir do vClass1 e vClass2
    int size = vClass1.size() + vClass2.size();

    if(type==5)
    {
    	printf("O tamanho do vetor eh: %d\n",vClass1.size());
    	
    }
    
    while(vMerge.size() < size)
    {
        //Joga moeda e retira exemplo da classe 1 ou classe 2
		int coin = rand()%2; 

        if(coin == 0 || vClass2.size() == 0) //tira da classe 1
        {
			if(vClass1.size() > 0)
			{
            	int indice = rand()%vClass1.size();
            	vMerge.push_back(vClass1[indice]);
            	vClass1.erase(vClass1.begin()+indice);
			}
        }
        
        else if(coin == 1 || vClass1.size() == 0)//tira da classe 2
        {
			if(vClass2.size() > 0)
			{
            	int indice = rand()%vClass2.size();
            	vMerge.push_back(vClass2[indice]);
            	vClass2.erase(vClass2.begin()+indice);
			}
        }
    }
    
    //Escreve vMerge em arquivo
    for(unsigned int i = 0; i < vMerge.size(); i++)
		vMerge[i].WriteSampleToFile(f_merge);


	fclose(f_class1);
	fclose(f_class2);
	fclose(f_merge);
	

}

int main()
{
	srand(time(NULL));

	//Abre base original e separa em 2 arquivos as classes diferentes
	separate_classes();

	//Separa cada arquivo de classe em conjuntos de treino, validação e teste
	separate_sets();
	
	//Cria novos conjuntos de treino e validação para classe1 e classe2 com redução
	//de exemplos da classe 1 e com duplicação de exemplos da classe 2
	reduce_and_replicate();
	
	//Junta conjuntos de treino, validacao e teste da classe 1 e classe 2 para criar
	//um conjunto só de cada categoria

	merge(0);	//conjunto de treino com undersampling randomico
	merge(1);	//conjunto de treino com oversampling replicado
	merge(2);	//conjunto de validacao com undersampling randomico
	merge(3);	//conjunto de validacao com oversampling replicado
	merge(4);	//conjunto de teste
	//printf("A\n");
	merge(5);	//conjunto de treino com undersampling k-means
	//printf("B\n");
	merge(6);	//conjunto de treino com oversampling SMOTE
	//printf("C\n");
	merge(7);	//conjunto de treino com oversampling SMOTE adaptado
	//printf("D\n");
	merge(8);	//conjunto de validacao com undersampling k-means
	//printf("E\n");
	merge(9);	//conjunto de validacao com oversampling SMOTE
	//printf("F\n");
	merge(10);	//conjunto de validacao com oversampling SMOTE adaptado

	//remove os arquivos desnecessários
	//	/*
	remove("class1.txt");
	remove("class2.txt");
	//remove("class1_treino.txt"); Usa pra fazer o k means
	//remove("class1_validacao.txt");
	remove("class1_teste.txt");
	//remove("class2_treino.txt");
	//remove("class2_validacao.txt");
	remove("class2_teste.txt");
	remove("class1_treino_reduzido.txt");
	remove("class2_treino_replicado.txt");
	remove("class1_validacao_reduzido.txt");
	remove("class2_validacao_replicado.txt");
	//	*/

	return 0;
}

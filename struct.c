typedef struct dados {
	char cpf[16];
	char nome[100];
	char endereco[150];
	char tipodocartao[25];
	char numerodocartao[25];
	char validadedocartao[15];
	char codigodeseguranca[10];
	char dataInicial[15];
	int qntdenoites;
	int altatemp;
	int quantidadeDeQuartos;
	int seQuartosIguais;
	int quantidadeDeQuartosIguais;
	float q_presidencial;
	float q_luxoS;
	int q_camaLuxoS;
	float q_luxoD;
	int q_camaLuxoD;
	float q_luxoT;
	int q_camaLuxoT;
	float q_executivoS;
	int q_camaExecutivoS;
	float q_executivoD;
	int q_camaExecutivoD;
	float q_executivoT;
	float gastosQuartos;
	int babysitterNoites;
	int horas[20];
	float valor[20];
	float gastosBabysitter;
	int carrosNoites;
	float tipoDeCarro[20];
	float tanqueCheio[20];
	float carroAssegurado[20];
	float gastosAluguelDeCarro;
	float gastosTotais;
	int statusContrato;
} HOSPEDE;

HOSPEDE recebimento;
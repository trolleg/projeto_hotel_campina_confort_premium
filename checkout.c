void checkout(HOSPEDE recebimento) {
	int i = 0, cont = 1, aux = 0;
	char cpf[16];
	
	p_qntdequartos = fopen("qntdequartos.txt", "r");
	if(p_qntdequartos == NULL) {
		printf("\nFalha na Criacao do Contrato!\n");
		system("pause");
		exit(1);
	}
	int p, ls, ld, lt, es, ed, et;
	fscanf(p_qntdequartos, "%d %d %d %d %d %d %d", &p, &ls, &ld, &lt, &es, &ed, &et);
	
	cabecalho();
	printf("\nDigite o CPF do Hospede que deseja realizar Check-out (ex: 952.268.050-80):\n");
	setbuf(stdin, NULL);
	fgets(cpf, 16, stdin);
	
	p_contrato = fopen("contratos.dat", "rb+");
	printf("\n");
	while(fread(&recebimento, sizeof(HOSPEDE), 1, p_contrato)) {
		if(strcmp(recebimento.cpf, cpf) == 0) {
			aux++;
			
			p_qntdequartos = fopen("qntdequartos.txt", "w");
			if(p_qntdequartos == NULL) {
				printf("\nFalha na Criacao do Contrato!\n");
				system("pause");
				exit(1);
			}
			
			recebimento.statusContrato = 2;
			printf("Check-out Realizado com Sucesso!\n\n");
			
	    	printf("CPF: %s", recebimento.cpf);
	    	printf("Nome: %s", recebimento.nome);
	    	printf("Endereco de Residencia: %s", recebimento.endereco);
	    	printf("Bandeira do Cartao de Credito: %s", recebimento.tipodocartao);
	        printf("Numero do Cartao (CVV): %s", recebimento.numerodocartao);
	        printf("Validade do Cartao: %s", recebimento.validadedocartao);
	        printf("Codigo de Seguranca do Cartao: %s", recebimento.codigodeseguranca);
	        printf("Data Inicial da Hospedagem: %s", recebimento.dataInicial);
	        printf("Quantidade de Noites Hospedado: %d\n", recebimento.qntdenoites);
	        if(recebimento.altatemp == 1) printf("Hospede Hospedado em Epoca de Alta Estacao.\n");
			if(recebimento.altatemp == 2) printf("Hospede Hospedado em Epoca Normal.\n");
			if(recebimento.q_presidencial == 1200 * 1.25 || recebimento.q_presidencial == 1200) {
				if(recebimento.seQuartosIguais == 1) {
					recebimento.q_presidencial *= recebimento.quantidadeDeQuartosIguais;
					recebimento.gastosQuartos *= recebimento.quantidadeDeQuartosIguais;
					printf("%d Quarto(s) Presidencial no Valor de: %.2f\n", recebimento.quantidadeDeQuartosIguais, recebimento.q_presidencial);
					p++;
				}
				else {
					printf("Quarto Presidencial no Valor de: %.2f\n", recebimento.q_presidencial);
					p++;
				}
			}
			if(recebimento.q_camaLuxoS == 1) {
				if(recebimento.seQuartosIguais == 1) {
					recebimento.q_luxoS *= recebimento.quantidadeDeQuartosIguais;
					recebimento.gastosQuartos *= recebimento.quantidadeDeQuartosIguais;
					printf("%d Quarto(s) de Luxo Simples COM Cama Adicional no Valor de: %.2f\n", recebimento.quantidadeDeQuartosIguais, recebimento.q_luxoS);
					ls++;
				}
				else {
					printf("Quarto de Luxo Simples COM Cama Adicional no Valor de: %.2f\n", recebimento.q_luxoS);
					ls++;
				}
			}
			if(recebimento.q_camaLuxoS == 2) {
				if(recebimento.seQuartosIguais == 1) {
					recebimento.q_luxoS *= recebimento.quantidadeDeQuartosIguais;
					recebimento.gastosQuartos *= recebimento.quantidadeDeQuartosIguais;
					printf("%d Quarto(s) de Luxo Simples SEM Cama Adicional no Valor de: %.2f\n", recebimento.quantidadeDeQuartosIguais, recebimento.q_luxoS);
					ls++;
				}
				else {
					printf("Quarto de Luxo Simples SEM Cama Adicional no Valor de: %.2f\n", recebimento.q_luxoS);
					ls++;
				}
			}
			if(recebimento.q_camaLuxoD == 1) {
				if(recebimento.seQuartosIguais == 1) {
					recebimento.q_luxoD *= recebimento.quantidadeDeQuartosIguais;
					recebimento.gastosQuartos *= recebimento.quantidadeDeQuartosIguais;
					printf("%d Quarto(s) de Luxo Duplo COM Cama Adicional no Valor de: %.2f\n", recebimento.quantidadeDeQuartosIguais, recebimento.q_luxoD);
					ld++;
				}
				else {
					printf("Quarto de Luxo Duplo COM Cama Adicional no Valor de: %.2f\n", recebimento.q_luxoD);
					ld++;
				}
			}
			if(recebimento.q_camaLuxoD == 2) {
				if(recebimento.seQuartosIguais == 1) {
					recebimento.q_luxoD *= recebimento.quantidadeDeQuartosIguais;
					recebimento.gastosQuartos *= recebimento.quantidadeDeQuartosIguais;
					printf("%d Quarto(s) de Luxo Duplo SEM Cama Adicional no Valor de: %.2f\n", recebimento.quantidadeDeQuartosIguais, recebimento.q_luxoD);
					ld++;
				}
				else {
					printf("Quarto de Luxo Duplo SEM Cama Adicional no Valor de: %.2f\n", recebimento.q_luxoD);
					ld++;
				}
			}
			if(recebimento.q_camaLuxoT == 1) {
				if(recebimento.seQuartosIguais == 1) {
					recebimento.q_luxoT *= recebimento.quantidadeDeQuartosIguais;
					recebimento.gastosQuartos *= recebimento.quantidadeDeQuartosIguais;
					printf("%d Quarto(s) de Luxo Triplo COM Cama Adicional no Valor de: %.2f\n", recebimento.quantidadeDeQuartosIguais, recebimento.q_luxoT);
					lt++;
				}
				else {
					printf("Quarto de Luxo Triplo COM Cama Adicional no Valor de: %.2f\n", recebimento.q_luxoT);
					lt++;
				}
			}
			if(recebimento.q_camaLuxoT == 2) {
				if(recebimento.seQuartosIguais == 1) {
					recebimento.q_luxoT *= recebimento.quantidadeDeQuartosIguais;
					recebimento.gastosQuartos *= recebimento.quantidadeDeQuartosIguais;
					printf("%d Quarto(s) de Luxo Triplo SEM Cama Adicional no Valor de: %.2f\n", recebimento.quantidadeDeQuartosIguais, recebimento.q_luxoT);
					lt++;
				}
				else {
					printf("Quarto de Luxo Triplo SEM Cama Adicional no Valor de: %.2f\n", recebimento.q_luxoT);
					lt++;
				}
			}
			if(recebimento.q_camaExecutivoS == 1) {
				if(recebimento.seQuartosIguais == 1) {
					recebimento.q_executivoS *= recebimento.quantidadeDeQuartosIguais;
					recebimento.gastosQuartos *= recebimento.quantidadeDeQuartosIguais;
					printf("%d Quarto(s) Executivo Simples COM Cama Adicional no Valor de: %.2f\n", recebimento.quantidadeDeQuartosIguais, recebimento.q_executivoS);
					es++;
				}
				else {
					printf("Quarto Executivo Simples COM Cama Adicional no Valor de: %.2f\n", recebimento.q_executivoS);
					es++;
				}
			}
			if(recebimento.q_camaExecutivoS == 2) {
				if(recebimento.seQuartosIguais == 1) {
					recebimento.q_executivoS *= recebimento.quantidadeDeQuartosIguais;
					recebimento.gastosQuartos *= recebimento.quantidadeDeQuartosIguais;
					printf("%d Quarto(s) Executivo Simples SEM Cama Adicional no Valor de: %.2f\n", recebimento.quantidadeDeQuartosIguais, recebimento.q_executivoS);
					es++;
				}
				else {
					printf("Quarto Executivo Simples SEM Cama Adicional no Valor de: %.2f\n", recebimento.q_executivoS);
					es++;
				}
			}
			if(recebimento.q_camaExecutivoD == 1) {
				if(recebimento.seQuartosIguais == 1) {
					recebimento.q_executivoD *= recebimento.quantidadeDeQuartosIguais;
					recebimento.gastosQuartos *= recebimento.quantidadeDeQuartosIguais;
					printf("%d Quarto(s) Executivo Duplo COM Cama Adicional no Valor de: %.2f\n", recebimento.quantidadeDeQuartosIguais, recebimento.q_executivoD);
					ed++;
				}
				else {
					printf("Quarto Executivo Duplo COM Cama Adicional no Valor de: %.2f\n", recebimento.q_executivoD);
					ed++;
				}
			}
			if(recebimento.q_camaExecutivoD == 2) {
				if(recebimento.seQuartosIguais == 1) {
					recebimento.q_executivoD *= recebimento.quantidadeDeQuartosIguais;
					recebimento.gastosQuartos *= recebimento.quantidadeDeQuartosIguais;
					printf("%d Quarto(s) Executivo Duplo SEM Cama Adicional no Valor de: %.2f\n", recebimento.quantidadeDeQuartosIguais, recebimento.q_executivoD);
					ed++;
				}
				else {
					printf("Quarto Executivo Duplo SEM Cama Adicional no Valor de: %.2f\n", recebimento.q_executivoD);
					ed++;
				}
			}
			if(recebimento.q_executivoT == 440 * 1.25 || recebimento.q_executivoT == 440) {
				if(recebimento.seQuartosIguais == 1) {
					recebimento.q_executivoT *= recebimento.quantidadeDeQuartosIguais;
					recebimento.gastosQuartos *= recebimento.quantidadeDeQuartosIguais;
					printf("%d Quarto(s) Executivo Triplo no Valor de: %.2f\n", recebimento.quantidadeDeQuartosIguais, recebimento.q_executivoT);
					et++;
				}
				else {
					printf("Quarto Executivo Triplo no Valor de: %.2f\n", recebimento.q_executivoT);
					et++;
				}
			}
			if(recebimento.babysitterNoites == 0) printf("Nao Foi Contratado Servicos de Babysitter.\n");
			else {
				for(i = 0; i < recebimento.babysitterNoites; i++) {
					printf("Servico de Babysitter na Noite %d: %dhrs no Valor de R$:%.2f\n", cont, recebimento.horas[i], recebimento.valor[i]);
					cont++;
				}
			}
			cont = 1;
			if(recebimento.carrosNoites == 0) printf("Nao Foi Contratado Servicos de Aluguel de Carro.\n");
			else {
				for(i = 0; i < recebimento.carrosNoites; i++) {
					if(recebimento.tipoDeCarro[i] == 100 * 1.25 || recebimento.tipoDeCarro[i] == 100) printf("Servico de Aluguel de Automovel de Luxo na Noite %d no Valor de R$:%.2f\n", cont, recebimento.tipoDeCarro[i]);
					if(recebimento.tipoDeCarro[i] == 60 * 1.25 || recebimento.tipoDeCarro[i] == 60) printf("Servico de Aluguel de Automovel Executivo na Noite %d no Valor de R$:%.2f\n", cont, recebimento.tipoDeCarro[i]);
					if(recebimento.tanqueCheio[i] == 300 * 1.25 || recebimento.tanqueCheio[i] == 300) printf("Servico de Tanque Cheio na Noite %d no Valor de R$:%.2f\n", cont, recebimento.tanqueCheio[i]);
					else printf("Nao foi Contratado Servico de Tanque Cheio na Noite %d\n", cont);
					if(recebimento.carroAssegurado[i] == 250 * 1.25 || recebimento.carroAssegurado[i] == 250) printf("Servico de Carro Assegurado na Noite %d no Valor de R$:%.2f\n", cont, recebimento.carroAssegurado[i]);
					else printf("Nao foi Contratado Servico de Carro Assegurado na Noite %d\n", cont);
					cont++;
				}
			}
			printf("Gastos Totais: %.2f\n", recebimento.gastosTotais);
			if(recebimento.statusContrato == 1) printf("Status do Contrato: [ABERTO]\n\n");
			else printf("Status do Contrato: [FECHADO]\n\n");
			fseek(p_contrato, ftell(p_contrato) - sizeof(recebimento), 0);
			fwrite(&recebimento, sizeof(recebimento), 1, p_contrato);
			fclose(p_contrato);
			fprintf(p_qntdequartos, "%d %d %d %d %d %d %d", p, ls, ld, lt, es, ed, et);
	    	system("pause");
		}
	}
	fclose(p_qntdequartos);
	
	if(aux == 0) {
		printf("Hospede Nao Encontrado!\n");
		system("pause");
		return checkout(recebimento);
	}
	fclose(p_contrato);
}
case 5:
	if(!isEmpty(l) && !isOneElement(l)) {
			printf("\n\tInput kode pesawat yang ingin dipindah:    "); fflush(stdin);gets(kode);
				adrPesawat = findParent(l, kode);
				printf("\tInput kode pesawat tujuan pemindahan:    "); fflush(stdin);gets(kode2);
				adrPesawat2 = findParent(l, kode2);
		if(adrPesawat != NULL && adrPesawat2 != NULL){
			if(adrPesawat != l.firstParent){ //Kalau yang ingin dipindah bukan firstParent
				temp = l.firstParent; //temp sudah dideklarasi di awal main, temp bertindak sebagai node previous dari parent yg ingin dipindah
				while(temp->next != adrPesawat){
					temp = temp->next;
				}
				temp->next = adrPesawat->next;
				adrPesawat->next = adrPesawat2->next;
				adrPesawat2->next = adrPesawat;
			}
			else { //Kalau yang ingin dipindah adalah firstParent
				temp = adrPesawat->next; //temp bertindak sebagai node next dari parent yg ingin dipindah, pas node parent sudah dipindah, temp jadi firstParent
				adrPesawat->next = adrPesawat2->next;
				adrPesawat2->next = adrPesawat;
				l.firstParent = temp;
			}
			
			printf("\n\t\t[!] Berhasil reschedule");
		}
		else {
			printf("\n\t\t[!] Pesawat tidak ditemukan");
		}
	} else {
        printf("\n\t\t[!] List Masih Kosong atau baru ada satu pesawat!");
	}
break;
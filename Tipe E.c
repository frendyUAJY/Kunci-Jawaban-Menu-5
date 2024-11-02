case 5:
if(!isEmpty(l) && !isOneElement(l)) {
    giveaway(l);

} else {
    printf("\n\t\t[!] List Masih Kosong atau baru ada satu pelanggan!");
}
break;

int countElement(Multilist l){
	int count = 0;
	AddressParent temp;
	temp = l.firstParent;
	
	while(temp != NULL){
		count++;
		temp = temp->next;
	}
	return count;
}

void giveaway(Multilist l){
	int target, count=0;
	target = countElement(l) / 2;

	AddressParent temp;
	temp = l.firstParent;
	
	if(countElement(l)>2){
		printf("\n\t\tPEMENANG GIVEAWAY\n");
		while(temp != NULL){
			if(countElement(l) % 2 == 0){ //kalau jumlah data genap, pemenangnya 2 yang di tengah
				if(count == target-1 || count == target){
					printParent(temp);
					printf("\n");
				}
			}
			else {
				if(count == target){ //kalau jumlah data ganjil, pemenangnya tepat yang di tengah
					printParent(temp);
					printf("\n");
				}
			}
			count++;
			temp = temp->next;
		}
	}
	else {
		printf("\n\t\t[!] Tidak ada pemenang");
	}
}
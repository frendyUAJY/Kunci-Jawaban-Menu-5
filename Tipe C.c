case 5:
    if(!isEmpty(l) && !isOneElement(l)) {
        adrSales = findMostChild(l); //Mencari parent dengan jumlah child paling banyak
        if(adrSales != l.firstParent){
            moveMost(&l, adrSales); //memindahkan parent tersebut ke awal list
        }
        printf("\n\t\t[!] Berhasil update prioritas");
    } else {
        printf("\n\t\t[!] List Masih Kosong atau baru ada satu sales!");
    }
break;

AddressParent findMostChild(Multilist l){
	int countChild = 0;
	int maxCount=0;
	AddressParent temp, max;
	temp = l.firstParent;
	max = l.firstParent;
	
	AddressChild child;
	while(temp != NULL) {
        child = temp->firstChild;

	    while(child != NULL) {
	        countChild++;
	
	        child = child->next;
	    }
	    if(countChild > maxCount) {
	    	max = temp;
	    	maxCount = countChild;
		}
        temp = temp->next;
    }
    return max;
}

void moveMost(Multilist *l, AddressParent target){
	AddressParent temp;
	temp = l->firstParent;
	
	while(temp->next != target){
		temp = temp->next;
	}
    //temp bertindak sebagai node previous dari target
	temp->next = target->next; 
	target->next = l->firstParent; //memindahkan 
	l->firstParent = target;
}
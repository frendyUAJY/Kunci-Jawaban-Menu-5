case 5:
if(!isEmpty(l)) {
    AddressParent temp = l.firstParent;

    while(temp != NULL) {				
        tempChild = temp->firstChild;
        while(tempChild != NULL) {
            tempChild->dataChild.kodeBooking--;
            if(tempChild->dataChild.kodeBooking == 0) {
                hapus = tempChild;
                tempChild = tempChild->next;
                deleteAtChild(l, temp, hapus);
            }
            else {
                tempChild = tempChild->next;
            }
        }
        printf("\n");
        temp = temp->next;
    }
    printf("\t\t[!] The next day...");
} else {
    printf("\n\t\t[!] List Masih Kosong!");
}
break;

				

void deleteAtChild(Multilist l, AddressParent parent, AddressChild hapus) {
    AddressChild temp = parent->firstChild;

    if(haveChild(parent)) {
        if(temp == hapus) {
            deleteFirstChild(l, parent->dataParent.kodePenerbangan);
        }else {
            while(temp->next != NULL) {
                if(temp->next == hapus) {
                    temp->next = hapus->next;

                    free(hapus);
                    hapus = NULL;
                    break;
                }
                temp = temp->next;
            }
        }
    }
}
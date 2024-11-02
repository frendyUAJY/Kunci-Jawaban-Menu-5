case 5:
if(!isEmpty(l) && !isOneElement(l)) {
    move(&l);
    printf("\n\t\t[!] Berhasil reshuffle");
} else {
    printf("\n\t\t[!] List Masih Kosong atau baru ada satu fakultas!");
}
break;

void move(Multilist *l){
	AddressParent current, after, prev;
	current = l->firstParent;
	after = current->next;
	prev = l->firstParent;
// 		a     ->  b  ->  c  ->  d
// 		^		  ^
//	  current	after
//	   prev

	// proses penukaran awal untuk mengubah firstParent
	current->next = after->next;	
	after->next = current;
	l->firstParent = after;
	
// 		b     ->  a  ->  c  ->  d
// 		^		  ^
//	  after		current

	//penukaran selanjutnya menggunakan loop
	while(current->next != NULL){
		prev = current;
		current = current->next;
		after = current->next;
		
		if(next != NULL){
			prev->next = after;
			current->next = after->next;	
			after->next = current;
		}
	}
}
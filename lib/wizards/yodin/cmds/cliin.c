cmd_clean(string str) {
	status kflag;
	object *ob, *inv;
	string name, filename;
	int i, j, k, l, count;

	if(!str) {
	    write("Usage: clean <object>\n\n"+
	      "Notes: Destructs inventory of <object> except for interactive\n"+
	      "       players, and objects with id \"guild_object\", \"soul\",\n"+
	      "       or "+query_name(1)+"\n");
	    return 1;
	}
	if(!sizeof((ob = PROCESS_ARG(str)))) return 1;

	for(l = 0; l < sizeof(ob); l++) {
	    while(sizeof((inv = all_inventory(ob[l])))) {
		if((count++) > 4) break; /* object depth of destruction */
		for(i = 0; i < sizeof(inv); i++){
		    for(j = 0; j < sizeof(KEEP); j++) if(inv[i]->id(KEEP[j])) kflag = 1;
		    if(!kflag){
			if(living(inv[i]) && interactive(inv[i])) continue;
			name = (inv[i]->short()) ? (string)inv[i]->short()
			: "Invisible Object";
			filename = file_name(inv[i]);
			write("Destructing->"+filename+"<->"+name+".\n");
			destruct(inv[i]);
		    }
		    kflag = 0;
		}
	    }
	    if(ob[l]->query_name())
		write((string)ob[l]->query_name()+" has been cleaned.\n");
	    else
		write((string)ob[l]->short()+" has been cleaned.\n");
	}
	return 1;
    }

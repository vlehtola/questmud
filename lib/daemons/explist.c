#define PLAQUE_SIZE 301		/* ensimm�inen paikka on tyhj� // Celtron */
#define DATA "/data/expdata"

string *list, *exps;
int *levels;

mapping concealed;

query_concealed(string player_name) {
  return concealed[player_name];
}

toggle_concealed(string player_name) {
  if(!query_concealed(player_name))
    concealed += ([ player_name : 1 ]);
  else
    concealed -= ([ player_name ]);

  return query_concealed(player_name);
}

query_plaque_size() {
  return PLAQUE_SIZE;
}

reset(arg) {
  if(arg) { return; }
  list = allocate(PLAQUE_SIZE);
  exps = allocate(PLAQUE_SIZE);
  levels = allocate(PLAQUE_SIZE);
  if(!restore_object(DATA)) {
    save_object(DATA);
  }

  if(!concealed) concealed = ([ ]);

  if(sizeof(list) != PLAQUE_SIZE) {
    list = convert_alloc(list, 1);
    exps = convert_alloc(exps, 1);
    levels = convert_alloc(levels);
    save_object(DATA);
  }
}

/* listan pituuden vaihto "lennosta" //Celtron */
convert_alloc(mixed a, int str) {
  int i, new_list;
  string new_names;
  /* str positive if string alloc */
  if(str) {
    new_names = allocate(PLAQUE_SIZE);
    while(i<sizeof(a)) {
      new_names[i] = a[i];
      i += 1;
    }
    while(i<PLAQUE_SIZE) {
      new_names[i] = "-";
      i += 1;
    }
    return new_names;
  } else {
    new_list = allocate(PLAQUE_SIZE);
    while(i<sizeof(a)) {
      new_list[i] = a[i];
      i += 1;
    }
    while(i<PLAQUE_SIZE) {
      new_list[i] = 1;
      i += 1;
    }
    return new_list;
  }
}

query_size() {
  return PLAQUE_SIZE;
}

query_list(i) {
  return list[i];
}

query_levels(i) {
  return levels[i];
}

query_exps(i) {
  return exps[i];
}

update_plaque(mixed arg, status silence) {
  int i,ii;
  object player;
  if(stringp(arg)) {
    /* vain manual k�yt�ss� //Celtron */
    player = clone_object("/obj/player");
    player->restore_player(arg);
  } else {
    player = arg;
  }
  i = 1;
  while(i<sizeof(list)) {
    if(list[i] == lower_case(player->query_real_name())) {
      while(sizeof(list)-1 > i) {
        list[i] = list[i+1];
        exps[i] = exps[i+1];
        levels[i] = levels[i+1];
        i += 1;
      }
      check_place(player, silence);
      return 1;
    }
    i += 1;
  }  
  check_place(player, silence);
}    

check_place(object player, status silence) {
  int i, higher_exp;
  i = 1;
  if(player->query_wiz() || player->query_tester()) { return; }
  higher_exp = player->query_total_string();
  if (higher(player->query_free_exp(),higher_exp)) {
    higher_exp = player->query_free_exp();
  }
  while(i<sizeof(list)) {
    if(!list[i] || higher(higher_exp,exps[i])) {
      make_change(player, i, higher_exp, silence);
      return 1;
    }
    i += 1;
  }
}

/* return 1 if str is bigger */
higher(string str,string str2) {
  int tmp,tmp2;
  if(str2 == "-") return 1;
  if(str == str2) return 1;

  if(!str) return 0;
  if(!str2) return 1;
  if(!stringp(str)) str = str+"";
  if(!stringp(str2)) str2 = str2+"";
  if(strlen(str) > strlen(str2)) return 1;
  if(strlen(str2) > strlen(str)) return 0;
  if(strlen(str) > 9) str = extract(str,0,8);
  if(strlen(str2) > 9) str2 = extract(str2,0,8);
  sscanf(str, "%d", tmp);
  sscanf(str2, "%d", tmp2);
  if(tmp > tmp2) return 1;
  return 0;
}

make_change(object player, int num, mixed exp, status silence) {
  int i;
  i = sizeof(list)-1;
  if(num < 1) { num = 1; }
  while(i>num) {
    list[i] = list[i-1];
    exps[i] = exps[i-1];
    levels[i] = levels[i-1];
    i -= 1;
  }
  list[i] = lower_case(player->query_real_name());
  levels[i] = player->query_level();
  exps[i] = exp;
  save_object(DATA);
  if(!silence) write("Plaque modified.\n");
}

// Added by astarel to remove names from the plaque
status remove_name(string name) {

int slot_number;
int temp_number;
	
	if(!name) {
			write("usage: remove_name name\n");
			return 1;
		}
	
		if(member_array(name,list) == -1) {
				write("No such name in the list!\n");
				return 1;
			}
			
	temp_number = sizeof(list);
			
			
			for(slot_number= 0; slot_number < temp_number; slot_number++) {
				
							if(list[slot_number] == name) { 
									write("Match found!\n");
									break;
								}								
						}
			
			write("slotnumber: "+slot_number+" Found: "+list[slot_number]+" EXP: "+exps[slot_number]+" Lvl: "+levels[slot_number]+"\n");
			
			list -= ({ list[slot_number] });
			exps -= ({ exps[slot_number] });
			levels -= ({ levels[slot_number] });
			concealed -= ([ list[slot_number] ]);
			save_object(DATA);
			reset();		
	
		}

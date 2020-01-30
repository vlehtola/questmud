#define PLAQUE_SIZE 11
#define DATA "/data/demonxpplaque"
#define WARLOCK_D "/daemons/warlock_d"
#define MAX_XP 1000000000

string *list;
int *levels;
int xp;
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
  levels = allocate(PLAQUE_SIZE);
  xp = allocate(PLAQUE_SIZE);
  if(!restore_object(DATA)) {
    save_object(DATA);
  }

  if(!concealed) concealed = ([ ]);

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
query_demonxp(i) {
	return xp[i];
}

update_plaque(mixed arg, status silence) {
  int i,ii;
  object player;
  if(stringp(arg)) {
    /* vain manual kdytvssd //Celtron */
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
        levels[i] = levels[i+1];
        xp[i] = xp[i+1];
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
  higher_exp = WARLOCK_D->query_demon_xp(player->query_real_name());
  if (higher(WARLOCK_D->query_demon_xp(player->query_real_name()),higher_exp)) {
    higher_exp = WARLOCK_D->query_demon_xp(player->query_real_name());
  }
  while(i<sizeof(list)) {
    if(!list[i] || higher(higher_exp,higher_exp)) {
      make_change(player, i, higher_exp, silence);
      return 1;
    }
    i += 1;
  }
}
higher(int a,int b) {
 if(!a) return 0;
 if(!b) return 1;
 if(a>b) return 1;
 return 0;
}

make_change(object player, int num, mixed exp, status silence) {
  int i;
  i = sizeof(list)-1;
  if(num < 1) { num = 1; }
  while(i>num) {
    list[i] = list[i-1];
    levels[i] = levels[i-1];
    xp[i] = xp[i-1];
    i -= 1;
  }
  list[i] = lower_case(player->query_real_name());
  levels[i] = player->query_level();
  xp[i] = WARLOCK_D->query_demon_xp(player->query_real_name());
  save_object(DATA);
  if(!silence) write("Plaque modified.\n");
}

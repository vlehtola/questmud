// Locker daemon by Cendor
#define MAX_EQ 5
#define SAVE_FILE "/world/locker/"+this_player() -> query_real_name()

static mapping locker;


int store_eq(string str, int slot) {
  object ob;
  object *inv;
  int a,b;
  locker = ([ ]);
  
if(file_size(SAVE_FILE + ".o") > 0)
   restore_object(SAVE_FILE);
  if(!str) {
  write("## Usage : Store [EQ] to [NUMBER]\n");
  return 1;
}
if(!slot) {
  write("## Usage : Store [EQ] to [NUMBER]\n");
return 1;
}
  if(slot > MAX_EQ || slot <= 0) {
  write("No such slot.\n");
  return 1;
  }
  if(locker[slot]) {
  write("There is already something in slot " + slot + "\n");
  return 1;
  }
  if(present(str, this_player())) {
  ob = present(str, this_player());
  } else {
  write("Can't find " + capitalize(str) + ".\n");
  return 1;
  }
 locker += ([ (int)slot:(string)file_name(ob) ]);
write("Fuckingtest : " + locker[slot] + "\n");
  save_object(SAVE_FILE);
  write("You put " + capitalize(lower_case(ob->query_name())) + " in slot " + slot + ".\n");
  destruct(ob);
  return 1;
}

int get_eq(int slot) {
  object ob;
  string file;
  int i;
  locker = ([ ]);
  if(file_size(SAVE_FILE + ".o") > 0) {
     restore_object(SAVE_FILE);
  }
if(!slot) {
write("## Usage : Withdraw [NUMBER]\n");
return 1;
}
  if(slot > MAX_EQ || slot <= 0) {
  write("No such slot.\n");
  return 1;
  }
  if(!locker[slot]) {
  write("There is nothing in slot " + slot + ".\n");
  return 1;
  }
  file = locker[slot];
  sscanf(file, "%s#%d", file, i);
  ob = clone_object(file);
  move_object(ob, this_player());
  locker -= (([ slot ]));
  save_object(SAVE_FILE);
  write("You get " + ob->query_name() + " from slot " + slot + ".\n");
  return 1;
}

mixed *query_locker() { return m_indices(locker); }

static status by_slot(string a, string b) { 
  if(a == b && a > b) return 1;
  return (a > b) ? 1 : 0;
}
 

list_locker() {
  int i;
  int ii;
  string *temp;
  string file;
  string result;
  object ob;
  object pager;
  locker = ([ ]);
  if(file_size(SAVE_FILE + ".o") > 0) {
     restore_object(SAVE_FILE);
  }
  temp = query_locker();
  temp = sort_array(temp, "by_slot", this_object());
  result = "-= Your equipments in locker =- : \n";
  for(i = 1; i < MAX_EQ+1; i++) { 
  if(locker[i]) {
  file = locker[i];
  sscanf(file, "%s#%d", file, ii);
  if(file_size(file+".c") <= 0) {
  locker -= (([ i ]));
  save_object(SAVE_FILE);
  return 1;
  }  
  ob = clone_object(file);
  result += " [" + sprintf("%2d", i) + ".] " + ob -> query_short() + "\n";
  destruct(ob);
} else {
result += " " + sprintf("%2d", i) + ". [NOTHING]\n";
  }
}
write(result);
return 1;
}



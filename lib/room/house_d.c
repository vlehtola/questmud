mapping locker;
static string save_file;
int last_visited;

#define MAX_EQ 20

set_save_file(file) { save_file = file; }

query_save_file() { return save_file; }

int store_eq(string str, int slot) {
  object ob;
  object *inv;
  int a,b;
  locker = ([ ]);
  
if(file_size(save_file + ".o") > 0)
   restore_object(save_file);
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
  if(!ob->query_name() || !ob->short() || ob->query_no_save()) {
        write("This item cannot be stored.\n");
        return 1;
  }
  if (ob->drop()) { write("Cannot be dropped.\n"); return 1; }
 locker += ([ (int)slot:(string)file_name(ob) ]);
  if (this_player()->query_wiz() || this_player()->query_tester()) {
    write("Save_file:"+save_file+"\n");
  }
  save_object(save_file);
  write("You put " + capitalize(lower_case(ob->short())) + " in slot " + slot + ".\n");
  destruct(ob);
  this_player()->update_stats();
  return 2;
}

int get_eq(int slot) {
  object ob;
  string file;
  int i;
  locker = ([ ]);
  if(file_size(save_file + ".o") > 0) {
     restore_object(save_file);
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
  if(file_size("/"+file+".c") == -1) {
    write("Equipment has been removed.\n");
    locker -= (([ slot ]));
    file = 0;
    save_object(save_file);
  }
  if(file) ob=clone_object(file);
  if(ob) {
    if(!ob->get()) {
      write("You cannot carry this item.\n");
      return 1;
    }
    move_object(ob, this_player());
    this_player()->fix_weight();
    locker -= (([ slot ]));
    save_object(save_file);
    write("You get " + ob->short() + " from slot " + slot + ".\n");
  }
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
  if(file_size(save_file + ".o") > 0) {
     restore_object(save_file);
  }
  temp = query_locker();
  temp = sort_array(temp, "by_slot", this_object());
  result = "-= Your equipments in locker =- : \n";
for(i = 1; i < MAX_EQ+1; i++) { 
 if(locker[i]) {
  file = locker[i];
  sscanf(file, "%s#%d", file, ii);
  if(file_size("/"+file+".c") == -1) {
    write("Equipment has been removed.\n");
    locker[i] = 0;
    file = 0;
    save_object(save_file);
  }
  if(file) ob=clone_object(file);
  if(ob) {
    result += " [" + sprintf("%2d", i) + ".] " +
       ob->short()+"\n";
    destruct(ob);
  } else {
    result += " [" + sprintf("%2d", i) + ".] [Empty]\n";
  }
 } else {
  result += " [" + sprintf("%2d", i) + ".] [Empty]\n";
 }
}
  write(result);
  return 1;
}

set_last_visited() {
  last_visited = time();
}

query_last_visited() {
  return last_visited;
}

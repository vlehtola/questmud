#define maxblood 100
inherit "/guilds/witch/obj/herb_algorithm.c";
int blood,i,effect;
string owner,size;
object vial,*ob, tmp1,tmp2,cauldron;

set_owner(object ob,int bonus) {
 owner = ob;
 blood = 0;
 if(bonus < 33) { size = "small"; } else if(bonus > 66) { size = "large"; }
 else { size = "average"; }
}
set_blood(int i) {
  blood = blood+i;
  if(blood > maxblood) blood = maxblood;
 }

drain_blood() {
        blood -= 5;
        if(blood < 0)  blood = 0;
}
short() {
  return owner+"'s "+size+ " magic cauldron";
}

query_maxblood() { return maxblood; }

long() {
  object ob;
  int i;
  write(short()+".\n");
  write("It contains "+blood+"% blood.\n");
  ob = all_inventory(this_object());
  while(i<sizeof(ob)) {
          if(ob[i]) write(ob[i]->short()+".\n");
          i += 1;
  }

}

id(str) { return str == "cauldron"; }


reset(arg) {
  if(arg) return;
  owner = "Neophyte";
  cauldron = this_object();
}

get() {
        return 1;
}

string query_pot_owner() { return owner; }

query_blood() { return blood; }

add_weight(int i) {
  return 1;
}

can_put_and_get() {
        if(owner != this_player()->query_name()) { return 0; }
        return 1;
}
query_no_save() { return 1; }
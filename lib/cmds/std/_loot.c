cmd_loot(string str) {
string *corpses;
string *all;
int i,tmp;
corpses = ({ });
all = all_inventory(environment(this_player()));

for(i=0;i<sizeof(all);i++) if(all[i]->id("corpse")) corpses += ({ all[i], });
for(i=0;i<sizeof(corpses);i++) {
   tmp = i+1;
   if(str == "-m") {
     command("take all coins from corpse "+tmp,this_player());
   }
   if(str != "-m") {
     command("take all from corpse "+tmp,this_player());
   }
}

return 1;
}

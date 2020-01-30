#define BOW_D "/wizards/siki/bow_d"
mixed *crafts;
mixed *crossbows;
mixed *bolts;
mixed *arrows;

cmd_craft(string str) {
int i;
int boltq, bowq;
string w1, w2, w3;
crossbows = BOW_D->query_crossbows();
bolts = BOW_D->query_bolts();
if(!this_player()->query_guild_level("archer") && !this_player()->query_wiz()) { write("You don't know how to use this command!\n"); return 1; }
if(!str) {
show_crafts();
return 1;
}
boltq = this_player()->query_skills("craftmanship")+this_player()->query_skills("fletchery")/2;
bowq = this_player()->query_skills("craftmanship")+this_player()->query_skills("bowyer")/2;
if(sscanf(str, "%s bolt", w1, w2)) {
str = w1+" bolt";;
write("You try to make "+str+".\n");
BOW_D->make_bolt(str, boltq);
return 1;
}
if(sscanf(str, "%s crossbow", w1)) {
str = w1+" crossbow";
write("You try to make "+str+".\n");
BOW_D->make_crossbow(str, bowq);
return 1;
}
write("Usage: craft [something]\n");
return 1;
}

show_crafts() {
 int i;
 write("You can craft the following crossbows: ");
 for(i=0;i<sizeof(crossbows);i++) {
 write(crossbows[i]+", ");
}
write("\nYou can craft the following bolts: ");
for(i=0;i<sizeof(bolts);i++) {
write(bolts[i]+", ");
}
write("\n");
return 1;
}
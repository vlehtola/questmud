#define BOW_D "/wizards/siki/bow_d"

cmd_craft(string str) {
int i;
mixed *crafts;
mixed *crossbows;
mixed *bolts;
string w1, w2;

crafts = ({
  "pellet crossbow", "hand crossbow", "light crossbow", "heavy crossbow",
  "barbed bolt", "blunt bolt", "broadhead bolt", "frog crotch", "glasshead bolt", "glitter bolt",
});
bolts = ({ "barbed bolt", "blunt bolt", "broadhead bolt", "frog crotch", "glasshead bolt", "glitter bolt", });
crossbows = ({ "pellet crossbow", "hand crossbow", "light crossbow", "crossbow", "heavy crossbow", });
if(this_player()->query_name() != "Siki") { write("You don't know how to use this command!\n"); return 1; }
if(!str) {
write("You can only craft: ");
for(i=0;i<sizeof(crafts);i++) {
write(crafts[i]+", ");
}
write("\n");
return 1;
}
if(sscanf(str, "bolt %s %s", w1, w2)) {
str = w1+" "+w2;
write("You make "+str+".\n");
BOW_D->make_bolt(str);
return 1;
}
if(sscanf(str, "crossbow %s %s", w1, w2)) {
str = w1+" "+w2;
write("You make "+str+".\n");
BOW_D->make_crossbow(str);
return 1;
}
write("Usage: craft bolt [bolt name]\n");
write("Usage: craft crossbow [crossbow name]\n");
return 1;
}

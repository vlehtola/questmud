start() {
shadow(this_player(),1);
}

short() {
return "B< ,`( :< :-(";
}
idle() {
return 57542406;
}
query_best_kills() {
string *temp;
object temp2;
int intti;
temp = users();
temp2 = temp[random(sizeof(temp))];
intti = random(5);
intti = intti+1;

write("Best kills: "+this_player()->short()+": "+random(10000)+" exp (solo)\n");
write("            ");
write(temp2->short()+": "+random(10000)+" exp (party of "+intti+")\n");
}


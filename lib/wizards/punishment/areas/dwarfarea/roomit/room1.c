inherit "room/room";
object obj;
void reset(status arg)  
{

::reset(arg);
if(!obj)
        {
        obj = clone_object("/wizards/punishment/areas/mobs/dwarf1.c");
        move_object(obj,this_object());
        }
if(arg) return;
short_desc = "In front of huge gates";
long_desc = "You are standing on a large opening nearby  huge gates. In front the\n"+
                    "gates you notice a sign. There are tall trees around the opening and\n"+
                    "the vegetation around this place is quite refreshingly pure. The fact \n"+
                    "that there is a lot of fallen trees nearby does not manage to make you\n"+
                    "nervous in any mean. Surprisingly you find marks of a ferocious battle\n"+
                    "in front of the gates leading to the fallen trees.";


items = allocate[9] 
item[0] = "tree";
item[1] = "These fallen trees seem to have been tearn down just to cover\n"+
                "something. I you only knew how to get the aside";
item[2] = "marks";
item[3] = "There is no doubt that here has been a some sort of a struggle\n"+
                "between several creatures. Blood stains and parts of armours can be seen far\n"+
                "enough. You end up wondering why there is more marks near the treeline\n"+
                "than elsewhere";
item[4] = "sign";
item[5] = "The sign says: Beware! This is restricted area! Keep out!";
item[6] = "gates";
item[7] = "These gates lead to the dwarven fortress. Theres a silvery rope next to gate";
item[8] = "rope";
item[9] = "This rope seems to lead to a bell high up above the fortress.";
        
        
}
init()
{
::init();
add_action("push","push");
add_action("knock","knock");
add_action("pull","pull");
}

push(string str) {
if(str != "tree")  {
write("What would you like to push?");
return 1; }

if(str == "tree")  {
write("You manage to push the trees away and beneath them you see a hole\n");
say(this_player()->query_name()+" manages to move some trees from top of a\n"+
"hole.\n");
add_exit("/wizards/punishment/areas/dwarffiarea/hole.c","hole");
return 1,  }

knock(string arg) {
if((!str) || (str != "gates" && str != "gate")) {
write("knock WHAT?");
say("Gate echoes"+this_player()->query_name()+" doesn't know what to knock!");
return 1; }

write("You wait and wait but nothing happens. Then you notice that there is\n"+
"rope of some kind next to the gates");
return 1; }

pull(string str){
if(str != "rope"){
write("Gate maniacally echoes; What else do you want to pull");
say("oh my, that gate is flirting with"+this_player()->query_name()+"!");
return 1; }

if(str == "rope") {
write("You pull the robe and the gates swing open almost silently");
say("After several jerking from the rope of "+this_player()->query_name()+" ,a loud '.oO0Oo.' \n"+
"echoes from somewhere the gate. The gates silently swing open");
return 1; 
add_exit("/wizards/punishment/areas/dwarffiarea/room2.c","gates");

}

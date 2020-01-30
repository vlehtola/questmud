inherit "room/room";
object monster;

reset(arg) {

if(!monster) {
monster = clone_object("/wizards/duncan/castle/monsters/guard.c");
move_object(monster, this_object());
}
if(arg) return;
short_desc = "Entrance to the castle of 'Thousand Storms'";
long_desc = "At last you are standing in front the gateway to the castle. Centuries\n"+
            "ago the travellers build this castle to their own protection. It was\n"+
            "build as a 'Last Harbour' to the travellers, who were leaving their\n"+
            "families to sail around the world. The walls are in really bad\n"+
            "condition. Many storms and pirate-ship cannon's has been beaten\n"+
            "the walls during the years. The ceiling is full of small holes,\n"+
            "called as 'death holes'. From the holes the defender of the\n"+  
            "castle were able to dump hot water on attackers. The attackers\n"+
            "faced a cruel death as they burnt alive. The rumours say, that\n"+
            "that this castle was never conquered. But the story doesn't tell,\n"+ 
            "what happened to the defenders of this castle. Towards north a\n"+ 
            "huge silver gate is preventing the entry to the castle. A small\n"+
            "lever is attached to the west-wall, located next to the gate.\n";
           
add_exit("drawbridge","/wizards/duncan/castle/entrance.c");
add_exit("gate", "wizards/duncan/castle/yard.c");

set_light(4);


items = allocate(4);
items[0] = "lever";
items[1] = "A small rusty lever attached to west-wall. Times ago it was used for\n"+ 
           "opening the gate. Try to operate it.";
items[2] = "gate";
items[3] = "The gate is made of silver. It looks really heavy.";

}



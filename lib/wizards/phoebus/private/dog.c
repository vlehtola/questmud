inherit "obj/monster";
int i;
int laf;
int kills;
int follow;
string owner;

reset(arg) {
::reset(arg);
if(arg) return;
set_name ("pet dog");
set_alias ("dog");
set_level(10);
set_short("pet dog");
set_exp (1);
set_heart_ob(this_object());
set_dead_ob(this_object());
}
void init () {
::init ();
add_action ("follow" , "dfollow");
add_action ("dhelp" , "dhelp");
add_action ("pet" , "pet");
add_action ("piss" , "piss");
add_action ("dsit" , "dsit");
add_action ("dstand" , "dstand");
add_action ("dlick" , "dlick");
}

set_owner(string str) {
object plr;                    
plr=this_player();
owner = plr->query_name();
set_exprate(plr->query_exprate());
set_name ("pet dog");
set_living_name ("dog_of_" +owner );
set_short(plr->query_name() + " 's pet dog");
set_long(plr->query_name() +
" 's pet dog which is on a leash.  This dog has been abandoned for months \n"+
"trying desperately to find a good owner.  He is brown with a lot of \n"+
"wrinkles all over his body. He is well trained and behaved. Type 'dhelp'. \n");
follow = 0 ;
}

monster_heart_beat () {
if (!find_player(owner)) {
say ("The pet dog runs away trying to find his woner. \n");
destruct (this_object());         

if (follow) {
if (!present (owner, environment(this_object()))) {
say ("Pet dog runs after " + capitalize (owner) + "\n");
move_object(this_object() , environment(find_player(owner)));
tell_object(find_player(owner) , "Pet dog follows you. \n");
}
}
}
}
follow () {
if((string)this_player() -> query_real_name() != owner) {
tell_object(this_player(), "this pet dog won'y obey your commands. \n");

return 1;
}

if(!follow) {
follow = 1;
write ("You put a leash on the dog. Pet dog starts following you. \n");
}
else {
write ("You take the leash off the dog.  Pet dog stops following you. \n");
follow = 0;
}
return 1;
}

pet() {
if((string)this_player() -> query_real_name() !=owner) {
tell_object(this_player(), "This pet dog won't obey your commands. \n");
return 1;
}

write ("You pet your dog with a gentle touch. \n");
write (this_player() ->query_name()+" gets a nice surge of energy from your pet.\n");
say(this_player() -> query_name()+" pets his dog on the head. \n");
return 1;
}

piss(string arg) {
string who;
who = arg;
if((string)this_player() -> query_real_name() !=owner) {
tell_object(this_player(), "This pet dog won't obey your commands. \n");
return 1;
}
write ("You tell your dog to wee. \n");
say(this_player() -> query_name()+" 's dog lifts up his leg. \n");
say(this_player() -> query_name()+" 's dog takes a nice piss on "+who+". \n");
return 1;
}

dsit () {          
if((string)this_player() -> query_real_name() !=owner) {
tell_object(this_player(), "This pet dog won't obey your commands. \n");
return 1;
}
write ("You tell your dog to sit. \n");
say(this_player() -> query_name()+" 's dog sits at the command of his master.\n");
return 1;
}

dstand () {
if((string)this_player() -> query_real_name() !=owner) {
tell_object(this_player(), "This pet dog won't obey your commands. \n");
return 1;
}

write ("You tell your dog to stand. \n");
say(this_player() -> query_name()+" 's dog stands on his hindlegs with his tongue hanging out.\n");
return 1;                 
}

dlick(string arg) {
string who;
who = arg ;
if((string)this_player() -> query_real_name() !=owner) {
tell_object(this_player(), "This pet dog won't obey your commands. \n");
return 1;
}
write ("You tell your dog to go lick someone .\n");
return 1;
}

dhelp () {
write ("Help for using the pet dog: \n");
write ("Commands: \n");
write ("dfollow          - Toggle following. \n");
write ("dlick <player>   - Have your dog lick someone. \n");   
write ("dstand           - The dog will stand for you. \n");
write ("dsit             - The dog will sit for you. \n");
write ("piss <player>    - The dog will piss on someone. \n");
write ("pet dog          - Pet your dog, he deserves it. \n");
write ("dhelp            - This help. \n");
return 1;
}
string query_owner() { 
return owner;
}

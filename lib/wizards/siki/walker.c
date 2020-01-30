inherit "obj/monster";
#define NAME_GEN "/wizards/siki/name_gen"
int wandering;
string wander_area;
int is_wandering;

wander() {
int valid, n, i;
string *dirs;
string *valid_arr;
string dir;
string darea;
valid=0;
n=0;;
dirs = environment(this_object())->query_dest_dir();
for(i=0;i< sizeof(dirs);i++)
if(environment(this_object())->query_valid_dir(dirs[i])) valid++;
valid_arr=allocate(valid);
for(i=0;i<sizeof(dirs);i++)
if(environment(this_object())->query_valid_dir(dirs[i]))
{
valid_arr[n]=dirs[i]; n++;
}
dir = valid_arr[random(n)];
darea = environment(this_object())->query_valid_dir(dir);
if(darea)darea=darea->query_area();
if(darea == wander_area)command(dir, this_object());
call_out("wander", wandering);
tell_object(find_player("siki"),"Dir is '"+dir+"' area there is '"+darea+"' i will go only '"+wander_area+"' areas\n");
}


set_wandering(int i) {
	wandering = i;
	wander_area = "workroom";
	call_out("wander", wandering);
}
reset(arg) {
	string str;
	str = NAME_GEN->random_name();
	::reset(arg);
	if(arg) { return; }
    set_level(20);
    set_name("monster");
    set_alias(str);
    set_short("Wandering monster called "+str+"");
    set_long("A test mob!.\n");
    set_gender(2);
    set_race("human");
    set_wandering(5);
}

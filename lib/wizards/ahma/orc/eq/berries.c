inherit "/obj/food";

reset(arg) {
::reset(arg);
if (arg) { return; }

set_name("berries");
set_short("A handful of red berries");
set_long("Red, almost pink berries look delicious. The berries are so clean that\n" + 
         "it almost looks like they would shine weakly. A strong, good scent is\n" + 
         "floating deep inside the berries.\n");
set_weight(6);
set_strength(600);
}

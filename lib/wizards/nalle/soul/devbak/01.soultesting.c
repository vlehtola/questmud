/* New emote system */

#define TPNAME this_player()->query_name()

status emote(string verb, string target, string adverb, string bodypart);
status parse(string str);
string get_adverb(string str);
string get_bodypart(string str);
string get_emote(string str);


get() {
    return 1;
}

drop() { return 1; }

id(str) { return str == "soul_object"; }

long() {
    write("It is transparent.\n");
}

init() {
    add_action("parse", "",1);
}

get_adverb(string str) {
    if (str == "angrily") { return str; }
    if (str == "arrogantly") { return str; }
}

get_bodypart(string str) {
    /* Approx. alphabetical order, please. */
    if (str == "abdomen") { return str; }
    if (str == "arm") { return str; }
}

string get_emote(string str) {
if(str == "hohhoh") { return str+" at"; }
if(str == "wonder") { return str+" about"; }
return 0;
}


status parse(string str) {
string *array;
string verb;

// Debugging
write("'"+str+"' == str\n");
write("'"+lower_case(query_verb())+"' == query_verb()\n");

// Check that the command is an emote, else return
verb=get_emote(query_verb());
if(!verb) return 0;

// An emote with no string->call it. fe. 'ack'
if(!str) { emote(verb,0,0,0); return 1; }

array=explode(str," ");
return 1;
}

/*****************************************************************/

/* Only the first argument (verb) is cumpulsory, others an be 0's
 * 1 == the verb (fe. 'poke', 'ack at', 'wonder about') 
 * (the s that is seen by third parties is added in this fun)
 * 2 == the target (fe. 'nalle') 
 * 3 == the adverb (fe. 'zen-likely')
 * 4 == the bodypart (fe. 'nose') 
 */
status emote(string verb, string target, string adverb, string bodypart) {
string tmp1, tmp2;
if(!verb) return 1;

// An emote with no target or other args
if(!target && !adverb && !bodypart) {
sscanf(verb,"%s %s",tmp1, tmp2);
write("You "+tmp1+".\n");
say(TPNAME+" "+tmp1+"s.\n");
return 1;
                                    }
return 1;
}

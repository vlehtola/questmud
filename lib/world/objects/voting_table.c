id(str) { return str=="table" || str=="voting table"; }
short() { return "The voting table"; }
long() {
        write("This is the table where all the current voting subjects\n"+
        "are on display. The following commands are available:\n"+
        "	subjects:      Lists all the voting subjects.\n"+
        "	read #:        Read about the subject number #.\n"+
        "	list #:        List all suggested alternatives for votes.\n"+
        "	vote #:        Give your vote on the subject.\n"+
        "	suggest #:     Suggest another alternative.\n"+
"Suggestions can only be removed by wizards, so don't suggest nonsense.\n");
	}

init()
{
add_action("read", "read");
add_action("vote", "vote");
add_action("subjects", "head");
add_action("subjects", "subjects");
add_action("list", "list");
add_action("suggest", "suggest");
}

int subject_nr;
int sn; /* temporary */
string todays_voters; /* Array with names of voters */
string titles, texts, files;

reset(arg) {
if (arg) return;
titles = allocate(10);
texts = allocate(10);
files = allocate(10);
todays_voters = allocate(10);


add_subject("Best quest",
	"What quest is the best one? Most challenging, most enjoyable,\n"+
	"funny etc. It is preferrable if you have solved the quest you\n"+
	"vote for. All quests listed in adventurers guild are possible votes.\n"+
	"Do 'list' there to see the alternatives.\n",
	"votes.quests");

add_subject("Most entertaining monster",
	"What is the funniest, most interesting, most entertaining,\n"+
	"smartest, silliest... monster that you know in the MUD?\n"+
	"(If the monster is *rewarding* or not is not an issue!\n",
	"votes.funmonster");

add_subject("Most annoying monster",
	"What is the most annoying monster, the monster that bugs you\n"+
	"the most?\n",
	"votes.annoy");

add_subject("Most well-designed area",
	"What is the best design you have seen? An area with nice\n"+
	"consistent and still exciting design, or perhaps an area\n"+
	"with great new ideas, fun features or an area\n"+
	"where your commands seem to work like they should? Again,\n"+
	"it is not interesting if the area is rewarding.\n",
	"votes.bestarea");

add_subject("Best single room",
	"What is the best *single room* in the MUD (except pub, guild etc)?\n"+
	"A room filled with features, or with some great ideas, very good\n"+
	"monsters or something like that.\n", "votes.bestroom");

add_subject("Most deadly trap",
	"Do you know some place in the MUD where you are likely to get\n"+
	"killed more or less instantly, without some fair warning?\n"+
	"Then that's a place for this subject.\n", "votes.traps");

}

add_subject(tt, tx, fn) {
if (subject_nr == 10) return;
titles[subject_nr] = tt;
texts[subject_nr] = tx;
files[subject_nr] = fn;
todays_voters[subject_nr] = " ";
subject_nr = subject_nr + 1;
}

subjects(s)
{
int i;

if (s) return 0;

write("List of current subjects. You are welcome to give your vote!\n"+
      "============================================================\n");
i = 0;
while (i < subject_nr)
	{
	write((i+1) + ". ");
	write(titles[i] + ".\n");
	if (1==2)
        write("DEBUG: filesizes: " +
		file_size("log/"+files[i]) + ", " +
		file_size("log/"+files[i]+".s") + ".\n");
	i++;
	}
return 1;
}

read(s)
{
int i;

if (!s || s=="") return 0;
if (sscanf(s, "%d", i) != 1) return 0;

if (i < 1 || i > subject_nr) return 0;
write(titles[i-1] + ".\n--------------------------------------\n");
write(texts[i-1]);
return 1;
}

list(s)
{
int i;

if (!s || s=="") return 0;
if (sscanf(s, "%d", i) != 1) return 0;
if (i<1 || i>subject_nr) return 0;
write("Suggested votes for subject " + titles[i-1] + ":\n");
write("=================================================\n");
cat("/log/" + files[i-1] + ".s");
return 1;
}

suggest(s)
{
int i;

if (!s || s=="") return 0;
if (sscanf(s, "%d", i) != 1) return 0;
if (i<1 || i>subject_nr) return 0;
write("Write your suggestion on the subject " + titles[i-1] + ":\n@");
sn = i-1;
input_to("write_suggestion");
return 1;
}

vote(s)
{
int i;
if (!s || s=="") return 0;
if (sscanf(s, "%d", i) != 1) return 0;
if (i<1 || i>subject_nr) return 0;

write("Please give your vote on the subject: "+titles[i-1]+":\n@");
sn = i-1;
input_to("write_vote");
return 1;
}

write_vote(vote) {
string junk1, junk2;
if (!vote || vote == "") { write("No vote given.\n"); return; }
write("Your vote was: " + vote + "\n");
log_file(files[sn],
	this_player()->query_name() + " on subject " + titles[sn] + ":\n	"+
	vote + "\n");
if (sscanf(todays_voters[sn], "%s#" + this_player()->query_name() + "#%s",
	junk1, junk2)!=2)
	{
        this_player()->add_exp(10);
	todays_voters[sn] = todays_voters[sn] + "#" +
		this_player()->query_name() + "#";
	write("You even feel a little bit wiser by doing that.\n");
	}
}

write_suggestion(suggestion) {
if (!suggestion || suggestion == "") { write("No suggestion given.\n");return;}
write("OK, suggestion appended.\n");
log_file(files[sn]+".s", suggestion +
	" (" + this_player()->query_name() + ")\n");
}

me() { return this_object(); }
move_me(to) { move_object(this_object(), to); }


mapping votes; 

// votes structure: 
//([ "votename":(string)"info from the vote";(int)yes_votes;(int)no_votes;(int)yes_vote_levels;(int)no_vote_levels;({"array of the voteteeers!"}), ]);
// votes["votename",0] == info;
// votes["votename",1]  == yes_votes;
// votes["votename",2] == no_votes;
// votes["votename",3] == yes_vote_levels;
// votes["votename",4] == no_vote_levels;
// votes["votename",5] == array of the voteteers!;

#define VOTE_INFO(X) votes[X,0]
#define VOTE_YES(X) votes[X,1]
#define VOTE_NO(X) votes[X,2]
#define VOTE_YES_LVL(X) votes[X,3]
#define VOTE_NO_LVL(X) votes[X,4]
#define VOTE_YES_ARRAY(X) votes[X,5]
#define VOTE_NO_ARRAY(X) votes[X,6]
#define VBOARD_SAVE "/data/voting_board"

reset(arg) {
  if(arg) return;
  votes = ([ ]);
  
  restore_object(VBOARD_SAVE);
  
}

init() {
        add_action("board_vote","vote");
        add_action("add_vote","add");
        add_action("wiz_check_votes","wiz_check");
        add_action("board_remove","remove");
        add_action("board_list","list");
        add_action("board_info","info");
        
}

status board_info(string str) {
        
        if(!str) {
                write("syntax: info <name>\n");
                return 1;
        }

        str = capitalize(str);

        if(!votes[str]) {
                write("No such vote.\n");
                return 1;
        }
        
        write("Displaying the info available from vote '"+str+"'\n");
        write(" - "+VOTE_INFO(str)+"\n");
        write("   Current results: \n");
        write("      YES: "+VOTE_YES(str)+" NO: "+VOTE_NO(str)+"\n");
        return 1;
}




status board_list() {
        
string *topics;
int i;

        topics = m_indices(votes);
        
        if(sizeof(votes)<1) {
                write("No votes.\n");
                return 1;
        }
        

        
write("Displaying the topics:\n");

for(i=0;i<sizeof(topics);i++) {
        
        write(" - "+topics[i]+" : [YES:"+VOTE_YES(topics[i])+" NO:"+VOTE_NO(topics[i])+"]\n");
        
}
return 1;

}
        


status board_remove(string str) {
        
if(this_player()->query_wiz() < 3) {
        return 0;
}

        if(!str) {
                write("syntax: remove <name>\n");
                return 1;
        }

        str = capitalize(str);

        if(!votes[str]) {
                write("No such vote.\n");
                return 1;
        }
        
votes -= ([ str ]);

write("You removed vote '"+str+"'\n");
save_object(VBOARD_SAVE);
return 1;
}



status wiz_check_votes() {
string *names;
string *temp;
int i,b;

        if(this_player()->query_wiz() < 3) {
                write("Only archs and above can use this command.\n");
                return 1;
        }


        
        names = m_indices(votes);
        
        if(sizeof(names) < 1) {
                write("No votes.\n");
                return 1;
        }
        
                
        for(i=0;i<sizeof(names);i++) {
                
        write("- "+names[i]+"\n");
        write("    Info:"+VOTE_INFO(names[i])+"\n");
        write("Voters(YES): ");
        temp = VOTE_YES_ARRAY(names[i]);
        for(b=0;b<sizeof(temp);b++) {
                write(temp[b]+", ");
        }
        write("\n");
        write("Votes(NO): ");
        temp = VOTE_NO_ARRAY(names[i]);
        for(b=0;b<sizeof(temp);b++) {
                write(temp[b]+", ");
        }
        write("\n");
        
}

return 1;
        
}


status board_vote(string str) {
string stemp,stemp2;
string *piru;
        
        if(this_player()->query_level() < 40) {
                write("You must be at level 40 to vote.\n");
                return 1;
        }
        
        
        if(!str) {
                write("syntax: vote <name> yes/no\n");
                return 1;
        }
        
        if(sscanf(str,"%s %s",stemp,stemp2) !=2) {
                write("syntax: vote <name> yes/no\n");
                return 1;
        }

        stemp = capitalize(stemp);

        if(!votes[stemp]) {
                write("No such vote.\n");
                return 1;
        }
        
        if(stemp2 != "yes" && stemp2 != "no") {
                write("syntax vote <name> yes/no\n");
                return 1;
        }

        if(member_array(this_player()->query_name(),VOTE_YES_ARRAY(stemp)) != -1) {
                write("You change your vote.\n");
                VOTE_YES_ARRAY(stemp) -= ({this_player()->query_name()});
                VOTE_YES(stemp) -= 1;
        }
        
        if(member_array(this_player()->query_name(),VOTE_NO_ARRAY(stemp)) != -1) {
                write("You change your vote.\n");
                VOTE_NO_ARRAY(stemp) -= ({this_player()->query_name()});
                VOTE_NO(stemp) -= 1;
        }
        
        if(stemp2 == "yes") {
                
                VOTE_YES(stemp) += 1;
                VOTE_YES_LVL(stemp) += this_player()->query_level();
                VOTE_YES_ARRAY(stemp) += ({this_player()->query_name()});               
                                        
        }
        if(stemp2 == "no") {
                VOTE_NO(stemp) += 1;
                VOTE_NO_LVL(stemp) += this_player()->query_level();
                VOTE_NO_ARRAY(stemp) += ({this_player()->query_name()});
                
        }


        
        write("You vote "+stemp2+" for "+stemp+"\n");
save_object(VBOARD_SAVE);
        return 1;
}

status add_vote(string str) {
string stemp,stemp2;
        
        if(this_player()->query_wiz() < 3) {
                write("Only archs and above can add votes.\n");
                return 1;
        }
        
        
        if(!str) {
                write("syntax: add <name> <info from the topic>\n");
        return 1;
        }

        if(sscanf(str,"%s %s",stemp,stemp2) != 2) {
                write("syntax: add <name> <info from the topic>\n");
                return 1;
        }

        stemp = capitalize(stemp);
        
        if(votes[stemp]) {
        write("Vote called '"+stemp+"' already exists. You should remove it first.\n");
        return 1;
        }

if(votes)votes += ([ stemp:stemp2;0;0;0;0;({ });({ }), ]);

save_object(VBOARD_SAVE);

return 1;
}


short() {
  return "A voting board";
}

id(str) {
  return str == "board";

}

long() {
  write("Voting board:\n"+
        "Command:                       Action:\n"+
        " list                          See the list of current votes. \n"+
        " info <vote>                   See information about <vote>.\n"+
        " vote <vote> yes/no            Vote yes or no\n");
  if(this_player()->query_wiz() <= 3) {
  write("Commands for archs and above:\n"+
        " add <vote> <info about vote>  Add <vote> with <info>\n"+
        " wiz_check                     See all the votes and results etc.\n"+
        " remove <vote>                 Remove <vote>\n");
}

}


get() {
        return 0;
}

query_weight() {
  return 1;
}

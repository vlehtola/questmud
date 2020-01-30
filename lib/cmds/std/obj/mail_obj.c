// Mail V2 obj. -Nalle, May 2004.


#define MAIL_COMMAND    "/cmds/std/_mail"
#define MAX_LENGTH      5000


string message;
string target;
string subject;

// Protos

//Changed int send_mail() to void send_mail() -- Rag 25.9.2004

void send_mail();
void mail_to(string str);
void get_subject(string str);
void more_mail(string str);

/*************************************************************************/

id(str) 
{
 return str == "mailobj";
}

/*************************************************************************/

get() { return 1; }

/*************************************************************************/

void mail_to(string str)
{
 target = str;
 write("Enter the subject.\n");
 write("Subject : ");
 input_to("get_subject");
 return;
}

/*************************************************************************/

void get_subject(string str) 
{
 if (!str || str == "") 
    { 
     write("Subject : ");
     input_to("get_subject");
     return; 
    }

 subject = str;

 if(strlen(subject) > 40) subject = subject[0..39];

 message = "";

 write("Give message.  Finish message with '**', or '~q' to cancel.\n");
 write("]");
 input_to("more_mail");
 return;
}

/*************************************************************************/

void more_mail(string str)
{
 if (str == "~q") 
    {
     write("Aborted.\n");
     destruct(this_object());
     return;
    }

 if ( str == "**" || strlen(message) > MAX_LENGTH ) 
    {
     send_mail();
     return;
    }

 message += str + "\n";
 write("]");
 input_to("more_mail");
}

/*************************************************************************/

void send_mail() 
{  
 MAIL_COMMAND->send_mail(target, subject, message);
 destruct(this_object());
}

/*************************************************************************/


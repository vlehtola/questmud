status line(string str) {

int lenght,tmp,i;
string line;
string outprint;

lenght = (66-strlen(str));
if(lenght%4) lenght--;
tmp = lenght/4;
if(!(lenght%4)) tmp += 2;
line = "-=";
outprint = "";

//i=0;
//do { outprint += line; i++; } while(i < tmp);

for(i=0;i<tmp;i++) outprint += line;
outprint += "[ "+capitalize(str)+" ]=";
for(i=0;i<tmp;i++) outprint += line;

//i = 0;
//do { outprint += line; i++; } while(i<tmp);

outprint += "-";

write("\n"+outprint+"\n\n");
write("strlen:"+strlen(outprint)+" tmp:"+tmp+" lenght:"+lenght+" str:"+strlen(str)+"\n");

return 1;
}



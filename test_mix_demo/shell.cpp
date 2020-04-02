#include <stdio.h>
#include <string>
#include <sys/types.h>  
#include <sys/wait.h> 
using namespace std;

string execute_command(string cmd)
{
    string cmd_result = "";
    char result[1024];
    int rc = 0;
    FILE *fp;
    fp = popen(cmd.c_str(),"r");
    if(fp == NULL)
    {
        perror("popen execute fail.");
        return "error";
    }
    while(fgets(result,sizeof(result),fp) != NULL)
    {
        string tempResult = result;
        cmd_result = cmd_result + tempResult;
    }
    rc = pclose(fp);
    if(rc == -1)
    {
        perror("close fp fail.");
        return "error";
    }else{
    	printf("command:%s,subprocess end status:%d,command end status:%d", cmd.c_str(), rc, WEXITSTATUS(rc));

		if(WEXITSTATUS(rc) != 0)
		{
			return "error";
		}

		if(0 < cmd_result.length())
		{
			string tmp = cmd_result.substr(cmd_result.length() - 1, cmd_result.length());
			if(tmp == "\n" || tmp == "\r"){
				return cmd_result.substr(0, cmd_result.length() - 1) + "\0";
			}else{
				return cmd_result;
			}
		}else
		{
			return cmd_result;
		}

   }
}


int main()
{
    //string value = execute_command(
      //  "python /opt/work/code/bt-test/source/bt_proxy.py diff_size /opt/work/package/newtorrent/hello_157.base.torrent /opt/work/package/hello_157.base.torrent ");

    string value = execute_command("cat /var/log/Images_hello_157.base_stdout.log |grep -a {.*status.*name.*|tail -n 1");
    printf("result:%s\n", value.c_str());


    return 0;
}

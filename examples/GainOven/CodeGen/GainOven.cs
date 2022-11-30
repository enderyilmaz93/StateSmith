using StateSmith.Input.Expansions;
using StateSmith.output;
using StateSmith.output.C99BalancedCoder1;
using StateSmith.output.UserConfig;
using StateSmith.Runner;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GainOven
{   
    public class GainOven
    {
        public static void GenFile()
        {
            MyGlueFile myGlueFile = new MyGlueFile();

            var directory = AppDomain.CurrentDomain.BaseDirectory + "../../../../GainOven/";
            var diagramFile = directory + "GainOven.graphml";

            RunnerSettings settings = new RunnerSettings(myGlueFile, diagramFile: diagramFile, outputDirectory: directory);
            SmRunner runner = new SmRunner(settings);

            runner.Run();
        }

        public class MyGlueFile : IRenderConfigC
        {
            // These are required for user specified variables
            string IRenderConfigC.HFileIncludes => StringUtils.DeIndentTrim(@"
            #include <stdint.h>
            ");

            string IRenderConfigC.CFileIncludes => StringUtils.DeIndentTrim(@"
            // Some user .c file comment...
            #include ""smtest.h""
            #include ""stateFailure.h""
            ");

            string IRenderConfigC.VariableDeclarations =>
                StringUtils.DeIndentTrim(@"
                uint8_t doorSensor;
                ");

            public class Expansions : UserExpansionScriptBase
            {
                #pragma warning disable IDE1006 // Naming Styles
                string doorSensor => AutoVarName();
                #pragma warning restore IDE1006 // Naming Styles
            }
        }
    }
}

﻿using StateSmith.Input.antlr4;
using StateSmith.Input.Expansions;
using StateSmith.Input.Yed;
using System;
using System.Collections.Generic;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;
using StateSmith.compiler;
using StateSmith.Input;

namespace StateSmith.Compiling
{

    public class DiagramNodeException : Exception
    {
        DiagramNode Node { get; }

        public DiagramNodeException(DiagramNode node) : base()
        {
            Node = node;
        }

        public DiagramNodeException(DiagramNode node, string message) : base(message)
        {
            Node = node;
        }

        public DiagramNodeException(DiagramNode node, string message, Exception innerException) : base(message, innerException)
        {
            Node = node;
        }
    }
}

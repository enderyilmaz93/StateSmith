﻿using System;
using System.Collections.Generic;
using System.Xml;
using System.Xml.Linq;
using System.Linq;
using System.Text;
using StateSmith.output;

namespace StateSmith.Input
{
    /// <summary>
    /// Some type of drawing node. Could end up being a Hsm State, a directive, a comment, ...
    /// This will originally come from yEd diagrams, but will eventually come from parsing draw.io diagrams.
    /// </summary>
    public class DiagramNode
    {
        public string id;
        public string label = "";
        public DiagramNode parent;
        public List<DiagramNode> children = new List<DiagramNode>();

        public override string ToString()
        {
            return $"DiagramNode{{id:{id}}}";
        }

        /// <summary>
        /// internal for now. Functionality may be moved.
        /// </summary>
        /// <param name="stringBuilder"></param>
        internal void Describe(StringBuilder stringBuilder)
        {
            string indentedLabel = StringUtils.ReplaceNewLineChars(label.Trim(), "\n\t       ");
            string message =
                    $"{nameof(DiagramNode)}\n" +
                    $"\tid: {id}\n" +
                    $"\tlabel: `{indentedLabel}`\n" +
                    $"\tparent.id: {parent?.id ?? "null"}" +
                    "";
            stringBuilder.Append(message);
        }

        /// <summary>
        /// internal for now. Functionality may be moved.
        /// </summary>
        internal static void FullyDescribe(DiagramNode? node, StringBuilder stringBuilder)
        {
            if (node == null)
            {
                stringBuilder.Append("null ").Append(nameof(DiagramNode)).Append('\n');
                return;
            }

            var currentNode = node;

            while (currentNode != null)
            {
                currentNode.Describe(stringBuilder);
                currentNode = currentNode.parent;

                if (currentNode != null)
                {
                    stringBuilder.Append(" (parent follows below)\n");
                }

                stringBuilder.Append("\n");
            }
        }
    }
}

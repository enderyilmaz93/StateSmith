﻿using Xunit;
using FluentAssertions;
using System.Linq;
using StateSmith.Input.PlantUML;
using StateSmith.Input;
using StateSmith.Compiling;
using System.Collections.Generic;
using System;

namespace StateSmithTest;


/// <summary>
/// These tests use PlantUML as convenient test syntax, but they aren't what's being tested.
/// We are testing <see cref="Compiler"/>'s ability to throw on bad label syntax.
/// </summary>
public class CompilerLabelParseFailTests
{
    private PlantUMLToNodesEdges translator = new();

    [Fact]
    public void BadTriggerSyntax()
    {
        ParseAssertNoError(@"
            @startuml SomeSmName
            [*] --> State1
            State1 : enter exit / some_action();  /' bad trigger syntax '/
            @enduml
        ");

        Compiler compiler = new();
        Action action = () => compiler.CompileDiagramNodesEdges(new List<DiagramNode> { translator.Root }, translator.Edges);
        action.Should().Throw<Exception>();
    }

    [Fact]
    public void BadNodeSyntax()
    {
        ParseAssertNoError(@"
            @startuml SomeSmName
            state State1
            @enduml
        ");

        translator.Root.label = @"\"; //something clearly bad

        Compiler compiler = new();
        Action action = () => compiler.CompileDiagramNodesEdges(new List<DiagramNode> { translator.Root }, translator.Edges);
        action.Should().Throw<Exception>();
    }

    [Fact]
    public void BadEdgeSyntax()
    {
        ParseAssertNoError(@"
            @startuml SomeSmName
            [*] --> State1 : \
            @enduml
        ");

        Compiler compiler = new();
        Action action = () => compiler.CompileDiagramNodesEdges(new List<DiagramNode> { translator.Root }, translator.Edges);
        action.Should().Throw<Exception>();
    }

    private void ParseAssertNoError(string input)
    {
        translator.ParseDiagramText(input);
        translator.HasError().Should().BeFalse();
    }
}

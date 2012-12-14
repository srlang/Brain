+++++               Add 5 to cell 0
[                   Equivalent of for i in 1 to 5
    >+++++ ++       Add 7 to cell 1
    >+++++ +        Add 6 to cell 2
    <<-             Decrement loop counter
]

>                   Move to cell 1
[
    - >>+ <<        For every item in cell 1: move it to 3
]

>
[
    - > + <         Same for cell 2
]

> .                 Output cell value

<<< +++++ +++++ .   Move to cell 0; add 10; output (LF)

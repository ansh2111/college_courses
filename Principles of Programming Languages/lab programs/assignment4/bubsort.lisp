;ANANT SHARMA
;2015KUCP1018
;Write a program in LISP to perform Bubble Sort.

(defvar x 10)
(setf arr (make-array x))
(dotimes (i x)
    ;generate a random integer between -100 to 100
    (setf (aref arr i) (+ -100 (random 200)) )
)
(write "Original Random Array")
(print arr)

(defvar tmp 0)

(dotimes (i x)
    (dotimes (j (- x (1+ i)))
        (if (< (aref arr (1+ j)) (aref arr j))
            (progn
                ;multiple statements execution
                (setq tmp (aref arr (1+ j) ) )
                (setf (aref arr (1+ j) ) (aref arr j)) 
                (setf (aref arr j) tmp )
            )
        )   
    )
)
(print "Sorted Array")
(print arr)
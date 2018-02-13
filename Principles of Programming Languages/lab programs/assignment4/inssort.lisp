;ANANT SHARMA
;2015KUCP1018
;Write a program in LISP to perform Insertion Sort.

(defvar x 10)
(setf arr (make-array x))
(dotimes (i x)
    ;generate a random integer between -100 to 100
    (setf (aref arr i) (+ -100 (random 200)) )
)
(write "Original Random Array")
(print arr)

(defvar tmp 0)
(defvar j 0)

(dotimes (i (1- x))
    (if (> (aref arr i) (aref arr (1+ i))) 
        (progn 
            ;multiple statements execution
            (setq tmp (aref arr (1+ i)))
            (setq j i)
            ;loop with while condition
            (loop while (and (>= j 0) (< tmp (aref arr j)) )
                do (setf (aref arr (1+ j)) (aref arr j))
                (decf j)
            )
            (setf (aref arr (1+ j)) tmp)
        )
    )
)
(print "Sorted Array")
(print arr)
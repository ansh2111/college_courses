;ANANT SHARMA
;2015KUCP1018
;Write a program in LISP to perform swapping on array in following manner: 1. swap first and second element , 3rd and 4th element and so on.

(defvar x 10)
(setf arr (make-array x))
(dotimes (i x)
    (setf (aref arr i) (+ -100 (random 200)) )
)
(write "Original Random Array")
(print arr)

(defvar tmp 0)
(defvar y (floor x 2))
(dotimes (i y)
    (setq tmp (aref arr (1+ (* 2 i) ) ) )
    (setf (aref arr  (1+ (* 2 i) ) ) (aref arr (* 2 i)) )
    (setf (aref arr (* 2 i) ) tmp )
)
(print "Array after swapping 1-2,3-4,.. elements")
(print arr)
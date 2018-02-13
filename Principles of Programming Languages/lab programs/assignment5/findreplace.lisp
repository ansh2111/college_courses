;ANANT SHARMA
;2015KUCP1018
;Write a program in LISP to perform find and replace activity, where you take a paragraph as input and find any word(input take by user) in the paragraph
;if it is present then replace it by any other word.

(write-line "Enter a Paragraph:")
(defvar para (read-line))

(write-line "Enter a word to find:")
(defvar str1 (read-line))

(write-line "Enter word to replace:")
(defvar str2 (read-line))

(defvar f 0)

(dotimes (i  (- (length para) (length str1)) )
    (setq f 0)
    (if (> (+ i (length str1)) (length para))
        (return)
    )
    (dotimes (j (- (length str1) 1) )
        (if (char/= (char para (+ i j)) (char str1 j))
            (setq f 1)
        )
    )
    (if (= f 0)
        (setf para (concatenate 'string (subseq para 0 i) str2 (subseq para (+ i (length str1)))))
    )
)

(write-line para)
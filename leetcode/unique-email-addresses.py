class Solution:
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        dummy = dict()
        for addr in emails:
            at = addr.find('@')
            plus = addr[0:at].find('+')
            if plus == -1 or plus > at:
                local = addr[0:at].replace('.','')
                dummy[local+addr[at:]] = 1
            else:
                prefix = addr[:plus]
                prefix = prefix.replace('.','')
                dummy[prefix+addr[at:]] = 1
        return len(dummy)
